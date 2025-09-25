# ISearchBoxInfo::GetCondition

## Description

Retrieves the contents of the search box as an [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) object.

## Parameters

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*, typically IID_ICondition.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the interface pointer requested in *riid*. This is typically [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

As opposed to the text string retrieved by [ISearchBoxInfo::GetText](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-isearchboxinfo-gettext), **GetCondition** retrieves the same information as a structured object, the methods of which can be used to parse and manipulate the search string.

We recommend that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

## See also

[ISearchBoxInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-isearchboxinfo)