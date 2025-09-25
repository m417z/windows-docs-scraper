# CreateTextServices function

## Description

The **CreateTextServices** function creates an instance of a text services object. The text services object supports a variety of interfaces, including [ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices) and the
Text Object Model (TOM).

## Parameters

### `punkOuter` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the outer object if the text services object is being created as part of an aggregate object. This parameter can be **NULL** if the object is not part of an aggregate.

### `pITextHost` [in]

Type: **[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)***

Pointer to your implementation of the [ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost) interface. This pointer must not be **NULL**.

### `ppUnk` [out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Pointer to a variable that receives a pointer to the private [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the text services object. You can call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on this pointer to retrieve [ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices) or [ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument) interface pointers.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the text services object was created successfully, the return value is S_OK.

If the function fails, one of the following COM error codes are returned. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | An invalid argument was passed in. |
| **E_OUTOFMEMORY** | Memory for text services object could not be allocated. |
| **E_FAIL** | The text services object could not be initialized. |

## Remarks

A text services object can be created as part of a standard COM-aggregated object. If it is, then callers should follow standard OLE32 rules for dealing with aggregated objects and caching interface pointers obtained through [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) from the private [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown).

## See also

**Conceptual**

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

**Reference**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)