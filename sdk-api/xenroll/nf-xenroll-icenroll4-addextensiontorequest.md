# ICEnroll4::addExtensionToRequest

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **addExtensionToRequest** method adds an extension to the request. This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `Flags` [in]

Specifies whether the extension is critical.
If **TRUE**, the extension being added is critical. If **FALSE**, it is not critical.

Note that **TRUE** is defined (in a Microsoft header file) for C/C++ programmers as one, while Visual Basic defines the **True** keyword as negative one. As a result, Visual Basic developers must use one (instead of **True**) to set this parameter to **TRUE**. However, to set this parameter to **FALSE**, Visual Basic developers can use zero or **False**.

### `strName` [in]

The [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that represents the extension name.

### `strValue` [in]

The base64-encoded or binary extension value.

## Return value

### VB

The return value is an **HRESULT**, with **S_OK** returned if the call is successful.