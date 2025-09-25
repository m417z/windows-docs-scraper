# ITextRangeProvider::GetChildren

## Description

Retrieves a collection of all elements that are both contained (either partially or completely) within the specified text range, and are child elements of the [enclosing element](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextrangeprovider-getenclosingelement) for the specified text range.

## Parameters

### `pRetVal` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)\*\***

An array of pointers to the [IRawElementProviderSimple](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple) interfaces for all child elements that are enclosed by the text range (sorted by the Start endpoint of their ranges).

If the text range does not include any child elements, an empty collection is returned.

This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each element retrieved with [ITextRangeProvider::GetChildren]() has a valid text range that can be retrieved through [RangeFromChild](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextprovider-rangefromchild). This includes any elements in the UI Automation tree between the [ITextProvider](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextprovider) and the child element.

### Examples

1. This example shows a text stream that contains an image link. The link is a child of the image, but both span the same text range and are exposed as embedded objects within the text stream.

    *Hello \ World*

    - Both image and link are also descendents of the stream's [ITextProvider](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextprovider), and either can be specified as the *childElement* in a call to [ITextProvider::RangeFromChild](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextprovider-rangefromchild).
    - Calling [ITextRangeProvider::RangeFromChild](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextprovider-rangefromchild), using either the image or the link, returns the same text range (*Range1*).
    - [GetChildren](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-getchildren) does not return the link.
    - [GetEnclosingElement](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextrangeprovider-getenclosingelement) does not return the image for any text range.
    - [GetEnclosingElement](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextrangeprovider-getenclosingelement) on *Range1* returns the link.
    - [GetChildren](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-getchildren) on *Range1* does not return any children.
    - [GetEnclosingElement](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextrangeprovider-getenclosingelement) on the text range for the stream's [ITextProvider](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextprovider) returns the provider.
    - [GetChildren](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-getchildren) on the text range for the stream's [ITextProvider](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextprovider) returns only the image.

2. This example shows a text stream that contains a two-cell table surrounded by text.

 *Start text

|  |  |
| --- | --- |
| Table Cell 1 | Table Cell 2 |

End Text*

    - Case 1: The stream's [ITextProvider](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextprovider) and entire text range
        - [ITextRangeProvider::GetEnclosingElement](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextrangeprovider-getenclosingelement) on the entire text range returns the stream's [ITextProvider](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextprovider).
        - GetChildren returns all child elements of the stream's [ITextProvider](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextprovider), only the table element in this case.
    - Case 2: Text range obtained by calling [ITextProvider::RangeFromChild](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextprovider-rangefromchild) on the table element:
        - [ITextRangeProvider::GetEnclosingElement](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextrangeprovider-getenclosingelement) returns the table element.
        - [ITextRangeProvider::GetChildren]()
returns both table cells.
    - Case 3: Text range that spans the visual content of *Table Cell 1 Table Cell 2*:
        - [ITextRangeProvider::GetEnclosingElement](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextrangeprovider-getenclosingelement) returns the table element.
        - [ITextRangeProvider::GetChildren]()
returns both table cells.
    - Case 4: Text range that spans the word *Cell* of *Table Cell 1*:
        - [ITextRangeProvider::GetEnclosingElement](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextrangeprovider-getenclosingelement) returns the first cell element.
        - [ITextRangeProvider::GetChildren]()
returns no elements.
    - Case 5: A degenerate (empty) text range that represents both starts (table and first cell):
        - [ITextRangeProvider::GetEnclosingElement](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextrangeprovider-getenclosingelement) returns the first cell element (the innermost element with a range that includes the degenerate range).
        - [ITextRangeProvider::GetChildren]()
returns no elements.

## See also

[ITextProvider](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextprovider), [ITextRangeProvider](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider), [GetEnclosingElement](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextrangeprovider-getenclosingelement), [ITextProvider::RangeFromChild](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-itextprovider-rangefromchild), [UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview), [Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)