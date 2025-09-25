# IWizardExtension::AddPages

## Description

Adds extension pages to the wizard by filling an array with handles to [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structures representing those pages.

## Parameters

### `aPages` [out]

Type: **HPROPSHEETPAGE***

A pointer to an array of [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) handles that represent the wizard dialog pages. Handles to **PROPSHEETPAGE** structures for the extension pages are added to this array.

### `cPages` [in]

Type: **UINT**

The count of elements in *aPages*.

### `pnPagesAdded` [out]

Type: **UINT***

The count of handles successfully added.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The array of handles pointed to by *aPages* can contain handles to wizard dialog pages preceding and following the extension pages. The array's pointer should be passed to this method so that its value is the first empty array element, ready to accept the handle of the first extension page, rather than simply the first element. Collaterally, the value passed in *cPages* should state the number of unused array elements instead of the total number.

For example, if two introductory host pages were added to an array called **hpages**, then the call to **IWizardExtension::AddPages** would appear as follows.

```
#define ARRAYSIZE(a)    (sizeof(a)/sizeof(a[0]))
g_iwe->AddPages(&hpages[2], ARRAYSIZE(hpages)-2, &nPages);
```

Do not confuse wizard pages, which are [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structures, with hosted HTML pages. One wizard dialog page can host many sequential HTML pages. This method supplies the number of wizard dialog pages added by the wizard extension, not the number of server-side HTML pages which are displayed in it.