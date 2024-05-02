#include <iostream>
#include "MyString.h"

struct Comment {
	MyString text;
	MyString createdBy;
};

class Document {
private:
	MyString content;
	Comment comments[50];
	unsigned currentCommentsCount = 0;
public:
	const MyString& getContent() const {
		return content;
	}

	void addComment(const Comment& comment) {
		if (currentCommentsCount >= 50) {
			return;
		}
		comments[currentCommentsCount++] = comment;
	}

	void addComment(Comment&& comment) {
		if (currentCommentsCount >= 50) {
			return;
		}
		comments[currentCommentsCount++] = std::move(comment);
	}

	void setContent(const MyString& text) {
		content = text;
	}

	void setContent(MyString&& text) {
		content = std::move(text);
	}
};

class Viewer {
protected:
	MyString name;
public: 
	void view(const Document& document) {
		std::cout << document.getContent() << std::endl;
	}
};

class Commenter : public Viewer {
public:
	void comment(Document& document, const Comment& comment) {
		document.addComment(comment);
	}

	void comment(Document& document, Comment&& comment) {
		document.addComment(std::move(comment));
	}
};

class Editor : public Commenter {
public:
	void edit(Document& document, const MyString& content) {
		document.setContent(content);
	}

	void edit(Document& document, MyString&& content) {
		document.setContent(std::move(content));
	}
};