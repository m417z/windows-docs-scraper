# ISecurityProperty::ReleaseSID

## Description

Releases the security identifier returned by one of the other [ISecurityProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecurityproperty) methods.

## Parameters

### `pSID` [in]

A reference to a security ID.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The argument passed in the pSid parameter is not a reference to a security ID. |

## Remarks

You should always invoke the **ReleaseSID** method to release any security ID pointers returned by the [GetDirectCallerSID](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isecurityproperty-getdirectcallersid), [GetDirectCreatorSID](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isecurityproperty-getdirectcreatorsid), [GetOriginalCallerSID](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isecurityproperty-getoriginalcallersid), and [GetOriginalCreatorSID](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isecurityproperty-getoriginalcreatorsid) methods.

## See also

[IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext)

[ISecurityProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecurityproperty)