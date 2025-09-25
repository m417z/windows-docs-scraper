# ITDirectory::ModifyDirectoryObject

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**ModifyDirectoryObject** method commits directory modifications to the server.

## Parameters

### `pDirectoryObject` [in]

Pointer to
[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject) modified.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDirectoryObject* parameter is not a valid pointer. |
| **RND_NOT_CONNECTED** | The [ITDirectory::Connect](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectory-connect) method has not been invoked or did not succeed. |
| **E_NOTIMPL** | This method is not implemented. |

## Remarks

Changes made to
[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject) will not take effect on the server until this method is called.

Some attributes cannot be modified, and an attempt to modify them will fail. For an example, see the Remarks section of
[ITDirectoryObjectUser::put_IPPhonePrimary](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobjectuser-put_ipphoneprimary).

## See also

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)