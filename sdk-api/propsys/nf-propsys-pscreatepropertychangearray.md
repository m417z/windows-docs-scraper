# PSCreatePropertyChangeArray function

## Description

Creates a container for a set of [IPropertyChange](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychange) objects. This container can be used with [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) to apply a set of property changes to a set of files.

## Parameters

### `rgpropkey` [in, optional]

Type: **const [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

Pointer to an array of [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures that name the specific properties whose changes are being stored. If this value is **NULL**, *cChanges* must be 0.

### `rgflags` [in, optional]

Type: **const [PKA_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-pka_flags)***

Pointer to an array of [PKA_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-pka_flags) values. If this value is **NULL**, *cChanges* must be 0.

### `rgpropvar` [in, optional]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to an array of [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures. If this value is **NULL**, *cChanges* must be 0.

### `cChanges` [in]

Type: **UINT**

Count of changes to be applied. This is the number of elements in each of the arrays *rgpropkey*, *rgflags*, and *rgpropvar*.

### `riid` [in]

Type: **REFIID**

Reference to the ID of the requested interface.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IPropertyChangeArray](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychangearray).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates a Component Object Model (COM) object that implements [IPropertyChangeArray](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychangearray). This object is a container for a set of [IPropertyChange](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychange) interfaces and can be used with [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) to apply a set of property changes to a set of files.

You must initialize COM with [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before you call [PSCreatePropertyChangeArray](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatepropertychangearray). COM must remain initialized for the lifetime of this object. The property change array executes in a single-threaded apartment (STA).

A property change array can be initialized either by specifying simple changes by using the parameters, or by using various [IPropertyChangeArray](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychangearray) methods to insert or append additional changes.

The parameters are tied together by their index value. For instance, for property rgpropkey[0], the new value rgpropvar[0] is applied as specified by rgflags[0]. The *cChanges* parameter states how many of these sets there are. Therefore, the number of elements in each array should be the same: ARRAYSIZE(rgpropkey) = ARRAYSIZE(rgflags) = ARRAYSIZE(rgpropvar) = cChanges.

[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) applies all changes in the property change array to a file simultaneously to avoid opening the file multiple times.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSCreatePropertyChangeArray](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatepropertychangearray) to set the [Comment](https://learn.microsoft.com/windows/desktop/Tapi/comment-ovr) property to "Fun" and [Rating](https://learn.microsoft.com/windows/desktop/wmformat/rating) to 4 on one or more files.

```cpp
// IFileOperation *pfo;
// Assume variable pfo has been initialized by calling SetOperationFlags,
// ApplyPropertiesToItems, and SetProgressMessage as appropriate.

PROPVARIANT rgpropvar[2] = {0};

HRESULT hr = InitPropVariantFromString(L"Fun", &rgpropvar[0]);

if (SUCCEEDED(hr))
{
    hr = InitPropVariantFromUInt32(RATING_FOUR_STARS_SET, &rgpropvar[1]);

    if (SUCCEEDED(hr))
    {
        REFPROPERTYKEY rgkey[2] = {PKEY_Comment, PKEY_Rating};
        PKA_FLAGS rgflags[2] = {PKA_SET, PKA_SET};
        IPropertyChangeArray *pChangeArray;

        hr = PSCreatePropertyChangeArray(rgkey, rgflags, rgpropvar, 2, IID_PPV_ARGS(&pChangeArray));

        if (SUCCEEDED(hr))
        {
            hr = pfo->SetProperties(pChangeArray);

            if (SUCCEEDED(hr))
            {
                hr = pfo->PerformOperations();
            }
            pChangeArray->Release();
        }
    }
    ClearPropVariantArray(rgpropvar, ARRAYSIZE(rgpropvar));
}
```

## See also

[PSCreateSimplePropertyChange](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatesimplepropertychange)