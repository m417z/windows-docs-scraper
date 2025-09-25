# IShellLibrary::SetOptions

## Description

Sets the library options.

## Parameters

### `lofMask` [in]

Type: **[LIBRARYOPTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryoptionflags)**

A bitmask that specifies the [LIBRARYOPTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryoptionflags) values to change in this call.

### `lofOptions` [in]

Type: **[LIBRARYOPTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryoptionflags)**

A bitmask that specifies the new value of each [LIBRARYOPTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryoptionflags) value to change. **LIBRARYOPTIONFLAGS** values that are not set in *lofMask* are not changed by this call.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[LIBRARYOPTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryoptionflags) is a bitwise enumerator, which means that more than one option flag can be set.

To change an option value, you must set the option value that you want to change in *lofMask* and then set or clear the value of the option in *lofOptions*.

#### Examples

The following example clears the LOF_PINNEDTONAVPANE library option.

```cpp

LIBRARYOPTIONFLAGS	maskValue;
LIBRARYOPTIONFLAGS optionValue;
HRESULT	hr = E_FAIL;

// set the maskValue variable to indicate
// which option value to change
maskValue = LOF_PINNEDTONAVPANE;

// set the optionValue variable to indicate
// the new value of the option
optionValue = ~LOF_PINNEDTONAVPANE;

// call the method
hr = library->SetOptions (maskValue, optionValue);
```

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[LIBRARYOPTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryoptionflags)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))