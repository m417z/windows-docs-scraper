# ORPC\_DBG\_ALL structure

The **ORPC\_DBG\_ALL** structure is used to pass parameters to the methods of the [**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify) interface.

> [!Note]
> Each method of the [**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify) interface uses a different combination of the members below. If a member is not indicated as used by a method, it is undefined when passed to that method.

## Members

**pSignature**

A pointer to a **BYTE** buffer that contains:

- First four bytes: the ASCII characters "MARB" in increasing memory order.
- Next 16 bytes: A **GUID** that identifies the notification being called. It contains one of the following:
1. [**ClientGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientgetbuffersize): 9ED14F80-9673-101A-B07B-00DD01113F11
2. [**ClientFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientfillbuffer):DA45F3E0-9673-101A-B07B-00DD01113F11
3. [**ClientNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientnotify):4F60E540-9674-101A-B07B-00DD01113F11
4. [**ServerNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servernotify):1084FA00-9674-101A-B07B-00DD01113F11
5. [**ServerGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servergetbuffersize):22080240-9674-101A-B07B-00DD01113F11
6. [**ServerFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-serverfillbuffer):2FC09500-9674-101A-B07B-00DD01113F11
- Next four-bytes: Reserved for future use.

> [!Note]
>
> Used by all methods of the [**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify) interface.

**pMessage**

A pointer to an [**RPCOLEMESSAGE**](https://learn.microsoft.com/windows/win32/api/objidlbase/ns-objidlbase-rpcolemessage) structure that contains RPC data marshalling information.

> [!Note]
>
> Used by the [**ClientFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientfillbuffer), [**ClientGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientgetbuffersize), [**ClientNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientnotify), [**ServerFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-serverfillbuffer), [**ServerGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servergetbuffersize), and [**ServerNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servernotify) methods.

**refiid**

A pointer to the IID of the [**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify) interface.

> [!Note]
>
> Used by the [**ClientFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientfillbuffer), [**ClientGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientgetbuffersize), [**ClientNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientnotify), [**ServerFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-serverfillbuffer), [**ServerGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servergetbuffersize), and [**ServerNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servernotify) methods.

**pChannel**

A pointer to the [**IRpcChannelBuffer**](https://learn.microsoft.com/windows/win32/api/objidlbase/nn-objidlbase-irpcchannelbuffer) interface of the COM RPC channel implementation on the server.

> [!Note]
>
> Used by the [**ServerFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-serverfillbuffer), [**ServerGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servergetbuffersize), and [**ServerNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servernotify) methods.

**pUnkProxyMgr**

A pointer to the [**IUnknown**](https://learn.microsoft.com/windows/desktop/api/Unknwn/nn-unknwn-iunknown) interface of the object involved in this debugger invocation. May be **NULL**, however, this reduces debugger functionality.

> [!Note]
>
> Used by the [**ClientFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientfillbuffer), [**ClientGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientgetbuffersize), and [**ClientNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientnotify) methods.

**pInterface**

A pointer to the COM interface of the method that will be invoked by this RPC. Must not be **NULL**.

> [!Note]
>
> Used by the [**ServerFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-serverfillbuffer), [**ServerGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servergetbuffersize), and [**ServerNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servernotify) methods.

**pUnkObject**

Must be **NULL**.

> [!Note]
>
> Used by the [**ServerFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-serverfillbuffer), [**ServerGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servergetbuffersize), and [**ServerNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servernotify) methods.

**hresult**

This member's purpose changes for each of the notifications below:

[**ClientGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientgetbuffersize): the number of bytes the client debugger will transmit to the server debugger. If zero, no information need be transmitted.

[**ClientNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientnotify): the **HRESULT** of the last RPC.

[**ServerGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servergetbuffersize): the number of bytes the client debugger will transmit to the server debugger. If zero, no information need be transmitted.

> [!Note]
>
> Used by the [**ClientGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientgetbuffersize), [**ClientNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientnotify), and [**ServerGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servergetbuffersize) methods.

**pvBuffer**

A pointer to an [**ORPC\_DBG\_BUFFER**](https://learn.microsoft.com/windows/win32/com/orpc-dbg-buffer) structure that contains the RPC marshalled debug information. Is undefined if **cbBuffer** is zero.

> [!Note]
>
> Used by the [**ClientFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientfillbuffer), [**ClientNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientnotify), [**ServerFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-serverfillbuffer), and [**ServerNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servernotify) methods.

**cbBuffer**

The length, in bytes, of the data pointed to by **pvBuffer**.

> [!Note]
>
> Used by the [**ClientFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientfillbuffer), [**ClientNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientnotify), [**ServerFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-serverfillbuffer), and [**ServerNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-servernotify) methods.

**lpcbBuffer**

The number of bytes the client debugger will transmit to the server debugger. If zero, no information need be transmitted. This value supersedes the value returned in **hresult**.

> [!Note]
>
> Used by the [**ClientFillBuffer**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientfillbuffer), [**ClientGetBufferSize**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify-clientgetbuffersize) methods.

**reserved**

Reserved. Do not use.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | N/A |

## See also

[**ORPC\_DBG\_BUFFER**](https://learn.microsoft.com/windows/win32/com/orpc-dbg-buffer)

[**ORPC\_INIT\_ARGS**](https://learn.microsoft.com/windows/win32/com/orpc-init-args)

[**DllDebugObjectRPCHook**](https://learn.microsoft.com/windows/win32/com/dlldebugobjectrpchook)

[**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify)

