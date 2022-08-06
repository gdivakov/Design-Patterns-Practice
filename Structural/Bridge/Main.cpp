#include "Bridge.h"

// When there are several implementations of some functionality, 
// it can be useful to separate the code into 2 classes - Abstraction and Implementation [1]

// When a class needs to be extended in two independent planes [2]

// If implementation should be replaceable during runtime [3]

//void main()
//{
//	Device* tv = new TV();
//	Device* ps = new PlayStation();
//
//	RemoteController* tvController = new RemoteController(tv);
//	tvController->toggleEnabled();
//
//	ModernRemoteController* psController = new ModernRemoteController(ps);
//	psController->toggleEnabled();
//	psController->mute();
//}