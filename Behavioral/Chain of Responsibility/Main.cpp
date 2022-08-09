#include "Chain.h"

// When a program must process a variety of requests in several ways w/ different handlers [1]
// When handlers should be processed sequentially [2]
// When need to form handlers dynamically [3]

//void main()
//{
//	AuthHandler* logIn = new AuthHandlerLogIn();
//	AuthHandler* logging = new AuthHandlerLogging();
//	AuthHandler* sendEmail = new AuthHandlerSendEmail();
//
//	logIn->setNext(logging)->setNext(sendEmail);
//
//	Request* req = new Request();
//
//	logIn->handle(req);
//
//	delete logIn;
//	delete sendEmail;
//	delete logging;
//	delete req;
//}