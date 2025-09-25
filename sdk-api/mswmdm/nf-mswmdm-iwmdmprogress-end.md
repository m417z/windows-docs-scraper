# IWMDMProgress::End

## Description

The **End** method indicates that an operation is finished.

## Return value

The return value from the method is ignored by Windows Media Device Manager.

## Remarks

This method is called by various interfaces to indicate that an operation is ending. Windows Media Device Manager ignores any return code returned by the **End** method because the operation is completed or terminated before this method is called.

#### Examples

The following C++ code is an implementation of the **End** method

```cpp

HRESULT End()
{
    // TODO: Display the message: "IWMDMProgress::End called."
    return S_OK; // Unnecessary, since this is ignored.
}

```

## See also

[Enabling Notifications](https://learn.microsoft.com/windows/desktop/WMDM/enabling-notifications)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)

[IWMDMProgress2::End2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress2-end2)

[IWMDMProgress3::End3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-end3)