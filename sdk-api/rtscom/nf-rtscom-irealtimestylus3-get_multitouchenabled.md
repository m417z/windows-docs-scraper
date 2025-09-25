# IRealTimeStylus3::get_MultiTouchEnabled

## Description

Indicates whether the [IRealTimeStylus3](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus3) object has multitouch input enabled.

This property is read/write.

## Parameters

## Remarks

The following table lists the defined opt-in options for multitouch.

| Name | Description | Value |
| --- | --- | --- |
| TABLET_ENABLE_MULTITOUCHDATA | Indicates opt-in for multitouch data. | 0x01000000 |

#### Examples

The following example demonstrates how to enable multitouch using the [RealTimeStylus3](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus3) interface.

```cpp

CComQIPtr<IRealTimeStylus3> spRealTimeStylus3 = g_spRealTimeStylus;
if(spRealTimeStylus3 == NULL)
{
    return FALSE;
}
HRESULT hr = spRealTimeStylus3->put_MultiTouchEnabled(TRUE);
if(FAILED(hr))
{
    return FALSE;
}
```

The following example shows how to explicitly set the TABLET_ENABLE_MULTITOUCHDATA property on a window.

```cpp

    //Set the window property
    ATOM m_atom = ::GlobalAddAtom(MICROSOFT_TABLETPENSERVICE_PROPERTY);
    m_dwProperty = TABLET_ENABLE_MULTITOUCHDATA;
    ::SetProp(m_hwnd, (LPTSTR)m_atomPenService, (HANDLE)m_dwProperty);

    //A Window Property takes effect on the down action of the 1st finger.

    //process the LRESULT from WinProc:

    //A custom LRESULT CALLBACK
    GestureTest::WindowProcedure(
      HWND hwnd,
      UINT uMsg,
      WPARAM wParam,
      LPARAM lParam)
    {
    case WM_TABLET_QUERYSYSTEMGESTURESTATUS:
        return TABLET_ENABLE_MULTITOUCHDATA;
    }

```

## See also

[IRealTimeStylus3](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus3)