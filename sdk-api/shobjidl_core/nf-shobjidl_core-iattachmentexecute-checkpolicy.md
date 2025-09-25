# IAttachmentExecute::CheckPolicy

## Description

Provides a Boolean test that can be used to make decisions based on the attachment's execution policy.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Value | Meaning |
| --- | --- |
| S_OK | Enable |
| S_FALSE | Prompt |
| Any other failure code | Disable |

## Remarks

**IAttachmentExecute::CheckPolicy** examines a set of properties known collectively as *evidence*. Anything used to determine trust level is considered evidence. These properties are set using the following methods.

* [IAttachmentExecute::SetFileName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setfilename)
* [IAttachmentExecute::SetLocalPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setlocalpath)
* [IAttachmentExecute::SetReferrer](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setreferrer)
* [IAttachmentExecute::SetSource](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setsource)

The information returned by **IAttachmentExecute::CheckPolicy** enables an application to modify its UI appropriately for the situation.

**IAttachmentExecute::CheckPolicy** requires the application first to call either [IAttachmentExecute::SetFileName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setfilename) or [IAttachmentExecute::SetLocalPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setlocalpath).