# IMathInputControl::GetHoverIcon

## Description

Retrieves the icon to be used for the hover target to launch math input control.

## Parameters

### `HoverImage` [out, retval]

The address of the pointer to the hover target icon.

## Return value

The method returns an **HRESULT**. Possible return codes include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The icon could not be retrieved. |

## Remarks

Applications are strongly encouraged to use this icon if implementing a hover target.
The icon is returned in .ico format and will match the system dots per inch (DPI) setting.

The icon is provided as a 32-bit image with fixed width and height.
At 96 DPI, the values are Width = 63, Height = 49.
For other DPIs these values are changed accordingly.
For example, on a 144 DPI system: Width = 63 * 144 / 96 and Height = 49 *144 / 96.
The application that retrieves the hover icon is responsible for releasing the icon resources.

#### Examples

```cpp

CComPtr <IMathInputControl> g_spMIC; // Math Input Control

BOOL TestDlg::OnInitDialog(){

    HRESULT hr = CoInitialize(NULL);
    hr = g_spMIC.CoCreateInstance(CLSID_MathInputControl);

    CComPtr<IPictureDisp> hoverImage;
    CComPtr<IPicture> pictureHoverImage;

    g_spMIC->GetHoverIcon(&hoverImage);

    hoverImage.QueryInterface(&pictureHoverImage);

    short type;
    pictureHoverImage->get_Type(&type);

    if (type == PICTYPE_ICON){
        OLE_HANDLE oleHandle;
        hr = pictureHoverImage->get_Handle(&oleHandle);

        this->SetIcon((HICON)oleHandle, true);
    }

    return TRUE;
}
```

## See also

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)