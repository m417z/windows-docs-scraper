# SHHandleUpdateImage function

## Description

[**SHHandleUpdateImage** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Handles the **SHCNE_UPDATEIMAGE** Shell change notification.

## Parameters

### `pidlExtra` [in]

Type: **PCIDLIST_ABSOLUTE**

The index in the system image list that has changed, specified in the *pidl2* parameter of [IShellChangeNotify::OnChange](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishellchangenotify-onchange).

## Return value

Type: **int**

Returns -1 on failure or the index of the changed image list entry on success.

## Remarks

Use **SHHandleUpdateImage** only when the *pidl2* parameter received by your change notification callback is non-**NULL**.

#### Examples

The following example demonstrates the use of **SHHandleUpdateImage** in the implementation of [IShellChangeNotify::OnChange](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishellchangenotify-onchange).

```cpp
STDMETHODIMP CMyShellChangeNotify::OnChange(LONG lEvent,
                                            LPCITEMIDLIST pidl1,
                                            LPCITEMIDLIST pidl2)
{
    HRESULT hr = E_FAIL;
    int iImage;

    switch(lEvent)
    {
        // An image in the system image list has changed.
        case SHCNE_UPDATEIMAGE:
        {
            hr = S_OK;

            if (pidl2)
                iImage = SHHandleUpdateImage(pidl2);
            else
                iImage = *(int UNALIGNED *)((BYTE *)pidl1 + 2);

            if (iImage != -1)
            {
                // Process iImage as desired.
            }
            break;
        }
        // Other cases
    }
    return hr;
}
```

## See also

[IShellChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishellchangenotify)

[SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify)