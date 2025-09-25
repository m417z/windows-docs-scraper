# COINIT enumeration

## Description

Determines the concurrency model used for incoming calls to objects created by this thread. This concurrency model can be either apartment-threaded or multithreaded.

## Constants

### `COINIT_APARTMENTTHREADED:0x2`

Initializes the thread for apartment-threaded object concurrency (see Remarks).

### `COINIT_MULTITHREADED:0x0`

Initializes the thread for multithreaded object concurrency (see Remarks).

### `COINIT_DISABLE_OLE1DDE:0x4`

Disables DDE for OLE1 support.

### `COINIT_SPEED_OVER_MEMORY:0x8`

Increase memory usage in an attempt to increase performance.

## Remarks

When a thread is initialized through a call to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex), you choose whether to initialize it as apartment-threaded or multithreaded by designating one of the members of **COINIT** as its second parameter. This designates how incoming calls to any object created by that thread are handled, that is, the object's concurrency.

Apartment-threading, while allowing for multiple threads of execution, serializes all incoming calls by requiring that calls to methods of objects created by this thread always run on the same thread, i.e. the apartment/thread that created them. In addition, calls can arrive only at message-queue boundaries. Because of this serialization, it is not typically necessary to write concurrency control into the code for the object, other than to avoid calls to [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) and [SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage) during processing that must not be interrupted by other method invocations or calls to other objects in the same apartment/thread.

Multi-threading (also called free-threading) allows calls to methods of objects created by this thread to be run on any thread. There is no serialization of calls, i.e. many calls may occur to the same method or to the same object or simultaneously. Multi-threaded object concurrency offers the highest performance and takes the best advantage of multiprocessor hardware for cross-thread, cross-process, and cross-machine calling, since calls to objects are not serialized in any way. This means, however, that the code for objects must enforce its own concurrency model, typically through the use of synchronization primitives, such as critical sections, semaphores, or mutexes. In addition, because the object doesn't control the lifetime of the threads that are accessing it, no thread-specific state may be stored in the object (in [Thread Local Storage](https://learn.microsoft.com/windows/desktop/ProcThread/thread-local-storage)).

**Note** The multi-threaded apartment is intended for use by non-GUI threads. Threads in multi-threaded apartments should not perform UI actions. This is because UI threads require a message pump, and COM does not pump messages for threads in a multi-threaded apartment.

## See also

[CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex)

[IInitializeSpy::PostInitialize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iinitializespy-postinitialize)

[IInitializeSpy::PreInitialize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iinitializespy-preinitialize)

[Processes, Threads, and Apartments](https://learn.microsoft.com/windows/desktop/com/processes--threads--and-apartments)