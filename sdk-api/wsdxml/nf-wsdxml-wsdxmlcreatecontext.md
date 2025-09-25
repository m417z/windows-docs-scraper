# WSDXMLCreateContext function

## Description

Creates a new [IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext)
object.

## Parameters

### `ppContext` [out]

Pointer to a newly allocated
[IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext) object. If the function fails,
this parameter can be **NULL**.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppContext* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |