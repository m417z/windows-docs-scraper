# ISecurityProperty::GetOriginalCallerSID

## Description

Retrieves the security identifier of the base process that initiated the call sequence from which the
current method was called.

The preferred way to obtain information about the original caller is to use the
[ISecurityCallContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecuritycallcontext) interface.

## Parameters

### `pSID` [out]

A reference to the security ID of the base process that initiated the call sequence from which the current
method was called.

## Return value

This method can return the standard return values **E_INVALIDARG**,
**E_OUTOFMEMORY**, **E_UNEXPECTED**, and
**E_FAIL**, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The security ID of the base process that originated the call into the current object is returned in the parameter *pSid*. |
| **CONTEXT_E_NOCONTEXT** | The current object does not have a context associated with it because either the component was not imported into an application or the object was not created with one of the COM+ **CreateInstance** methods. |

## Remarks

You use the
**GetOriginalCallerSID** method to
determine the security ID of the original process that initiated the call sequence from which the current method
was called, not the originator (or creator) of the process. Although a pointer to an object can be passed through
a series of servers and users,
**GetOriginalCallerSID** always
returns the first server and user of the process, even if that user was not the original creator of the object.
The following scenario illustrates the functionality of the
**GetOriginalCallerSID** method.

:::image type="content" source="./images/ff4d2c22-6e80-48e0-a6ca-4622b703e9e9.png" border="false" alt-text="Diagram showing the results of the GetOriginalCallerSID method for object references passed between four servers running two base processes.":::

1. Base Process 1, running on Server A as user A, creates Object X, on Server B, running as user B.
2. Base Process 1 passes its reference on Object X to Base Process 2, running on Server D as user D.
3. Base Process 2 uses that reference to call into Object X.
4. Object X calls into Object Y, running on Server C. If Object Y then calls
   **GetOriginalCallerSID**, the
   security ID of user D is returned, not user A, who originally created the object.

**Note** Usually, an object's original caller is the same process as its original creator. The only situation in
which the original caller and the original creator would be different is one in which the original creator passes
a reference to another process and the other process initiates the call sequence (as in the preceding
example).

The path to the original caller is broken if any object along the chain was created by some means other than
[IObjectContext::CreateInstance](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-createinstance) or
[ITransactionContext::CreateInstance](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-itransactioncontext-createinstance).
For example, if Base Process 1 uses [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance)
to create Object X, when Object Y calls
**GetOriginalCallerSID** the security
ID it gets back is the security ID of user B, not user D. This is because the call sequence is traced back
through the objects' context and COM+ can create a context only for an object that is created with either
**IObjectContext::CreateInstance** or
**ITransactionContext::CreateInstance**.

You must call [ReleaseSID](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isecurityproperty-releasesid) on a security
ID when you finish using it.

## See also

[ISecurityProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecurityproperty)