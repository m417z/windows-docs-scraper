# IShellPropSheetExt::AddPages

## Description

Adds one or more pages to a property sheet that the Shell displays for a file object. The Shell calls this method for each property sheet handler registered to the file type.

## Parameters

### `pfnAddPage` [in]

Type: **LPFNADDPROPSHEETPAGE**

A pointer to a function that the property sheet handler calls to add a page to the property sheet. The function takes a property sheet handle returned by the [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) function and the *lParam* parameter passed to this method.

### `lParam` [in]

Type: **LPARAM**

Handler-specific data to pass to the function pointed to by *pfnAddPage*.

## Return value

Type: **HRESULT**

If successful, returns a one-based index to specify the page that should be initially displayed. See Remarks for more information.

## Remarks

For each page that the property sheet handler needs to add to a property sheet, the handler fills a [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure, calls the [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) function, and then calls the function pointed to by *pfnAddPage*.

The **LPFNADDPROPSHEETPAGE** function pointer type is defined in Prsht.h as shown here. It accepts a handle to a [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure and function-defined data through *lParam*.

``` syntax
typedef BOOL (* LPFNADDPROPSHEETPAGE)(HPROPSHEETPAGE, LPARAM);
```

You can request through your implementation that a particular property sheet page be displayed first, instead of the default page. To do so, return the one-based index of the desired page relative to the pages you added. For example, if you added three property sheet pages, A, B, and C, and you want B to be the selected page, then the return value should be 2. Note that this return value is only a request. The property sheet might still display the default page.