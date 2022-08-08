#include "Decorator.h"

// When need to add responsibilities to objects on the fly,
// imperceptible to the code that uses them [1]

// When impossible to expand responsibilities with inheritance [2]

//void main()
//{
//	Notifier* emailNotifier = new EmailNotifier();
//	Notifier* slackNotifier = new SlackNotifier(emailNotifier);
//	Notifier* fbNotifier = new FacebookNotifier(slackNotifier);
//
//	fbNotifier->notify();
//}