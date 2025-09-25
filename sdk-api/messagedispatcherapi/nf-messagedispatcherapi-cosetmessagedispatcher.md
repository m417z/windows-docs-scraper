# CoSetMessageDispatcher function

## Description

Registers or unregisters the per-thread message dispatcher that is to be invoked when there are window messages available to dispatch within COM wait APIs on an ASTA thread. This function is usually called by CoreWindow, but in certain circumstances other components that need to specialize how messages are dispatched on an ASTA thread can also call this function.

## Parameters

### `pMessageDispatcher` [in, optional]

If non-null, message dispatcher object to register. This object must also implement [IWeakReferenceSource](https://learn.microsoft.com/windows/desktop/api/weakreference/nn-weakreference-iweakreferencesource). If null, unregisters the current message dispatcher.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is supported only in ASTA threads. An attempt to set the message dispatcher on a non-ASTA thread silently fails with no side effects.

An attempt to set an object that does not implement [IWeakReferenceSource](https://learn.microsoft.com/windows/desktop/api/weakreference/nn-weakreference-iweakreferencesource) silently fails with no side effects.

A call to this function with a valid and non-null *pMessageDispatcher* parameter registers this object to receive a [PumpMessages](https://learn.microsoft.com/windows/desktop/api/imessagedispatcher/nf-imessagedispatcher-imessagedispatcher-pumpmessages) callback whenever there are window messages available to dispatch with COM wait APIs on that ASTA thread. A Windows Runtime weak reference to this object is held, and the object receives callbacks, until the registration is replaced or the ASTA uninitialized. Each call to this function replaces the previously registered message dispatcher, if any.

There is no way to check if a message dispatcher is registered on an ASTA thread or to retrieve a previously registered message dispatcher. This function should only be called under circumstances where it is known that this will not collide with another registration, specifically:

* In Windows Store app UI threads, this function is called by CoreWindow to register its dispatcher. No other components should call this function on these threads.
* UI frameworks may support an authoring mode, in which applications are run in the desktop environment and therefore do not have a CoreWindow in their UI threads. In lieu of CoreWindow support, these UI frameworks may register a message dispatcher on UI threads to handle special window message processing usually handled by CoreWindow (such as accelerators). It is not required to call this function if the UI framework has no need for this functionality.
* [IAppVisibility](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iappvisibility) browsers are not restricted to the Windows Store app APIs and therefore may have their own custom window message processing using user32 APIs. However, these applications still have ASTA UI threads as provided by app object, and may register a message dispatcher to handle this special processing. It is not required to call this function if the browser has no need for this functionality.

The case of [IAppVisibility](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iappvisibility) browsers requires care to avoid CoreWindow replacing the browser’s message dispatcher. It is assumed that the browser has no need for CoreWindow’s dispatcher. The browser should call **CoSetMessageDispatcher** no sooner than its IViewProvider::Initialize, or, in the case of views that implement IInitializeWithWindowFactory, no sooner than after it has created a window on the thread.

## See also

[IAppVisibility](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iappvisibility)