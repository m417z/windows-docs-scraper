# FilterConnectCommunicationPort function

## Description

**FilterConnectCommunicationPort** opens a new connection to a communication server port that is created by a file system minifilter.

## Parameters

### `lpPortName` [in]

Pointer to a NULL-terminated wide-character string containing the fully qualified name of the communication server port (for example, L"\\MyFilterPort").

### `dwOptions` [in]

Connection options for the communication port. Prior to Windows 8.1, this value is set to 0.

| Value | Meaning |
| --- | --- |
| **FLT_PORT_FLAG_SYNC_HANDLE** | The handle returned in *hPort* is for synchronous I/O. This flag is available starting with Windows 8.1. |

### `lpContext` [in, optional]

Pointer to caller-supplied context information to be passed to the kernel-mode minifilter's connect notification routine. (See the *ConnectNotifyCallback* parameter in the reference page for [FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltcreatecommunicationport).) This parameter is optional and can be **NULL**.

### `wSizeOfContext` [in]

Size, in bytes, of the structure that the *lpContext* parameter points to. If the value of *lpContext* is non-**NULL**, this parameter must be nonzero. If *lpContext* is **NULL**, this parameter must be zero.

### `lpSecurityAttributes` [in, optional]

Pointer to a SECURITY_ATTRIBUTES structure that determines whether the returned handle can be inherited by child processes. For more information about the SECURITY_ATTRIBUTES structure, see the Microsoft Windows SDK documentation. This parameter is optional and can be **NULL**. If this parameter is **NULL**, the handle cannot be inherited.

### `hPort` [out]

Pointer to a caller-allocated variable that receives a handle for the newly created connection port if the call to **FilterConnectCommunicationPort** succeeds; otherwise, it receives INVALID_HANDLE_VALUE.

## Return value

**FilterConnectCommunicationPort** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

**FilterConnectCommunicationPort** opens a connection to a minifilter's communication server port on behalf of a user-mode application. The application uses the resulting connection port handle to communicate with the minifilter.

After it successfully calls **FilterConnectCommunicationPort**, the application can send messages to the minifilter through the connection port by calling [FilterSendMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtersendmessage). It can also receive and reply to messages from the minifilter by calling [FilterGetMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtergetmessage) and [FilterReplyMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterreplymessage), respectively. The connection port handle returned in the *hPort* parameter is passed as the first parameter to **FilterSendMessage**, **FilterGetMessage**, and **FilterReplyMessage**.

Any handle that is obtained from **FilterConnectCommunicationPort** must eventually be released by calling [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle).

## See also

[CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle)

[FilterGetMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtergetmessage)

[FilterReplyMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterreplymessage)

[FilterSendMessage](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtersendmessage)

[FltBuildDefaultSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltbuilddefaultsecuritydescriptor)

[FltCloseClientPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltcloseclientport)

[FltCloseCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltclosecommunicationport)

[FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltcreatecommunicationport)

[FltFreeSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltfreesecuritydescriptor)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)