# IMathInputControl::SetPreviewHeight

## Description

 Modifies the preview-area height in pixels.

## Parameters

### `Height` [in]

The preview-area height in pixels.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The height specified by the *Height* parameter is outside the control's bounds. |

## Remarks

The preview area has predefined minimum and maximum sizes that depend on the current height of the control.
If the method returns **S_FALSE**, the [GetPreviewHeight](https://learn.microsoft.com/windows/desktop/api/micaut/nf-micaut-imathinputcontrol-getpreviewheight) method will return the actual size characteristics of the control.

The following image shows the Math Input Control with the default preview height.

![Math input control with default preview height](https://learn.microsoft.com/windows/win32/api/micaut/images/mic.png)
The following image shows the Math Input Control with a custom preview height.

![Math input control with custom preview height](https://learn.microsoft.com/windows/win32/api/micaut/images/mic_big_preview.png)

#### Examples

```cpp

    CComPtr<IMathInputControl> g_spMIC; // Math Input Control

    // Set the preview height
    // Note:  Control must be initialized first
    void CMath_Input_Control_testDlg::OnBnClickedSetPreviewAreaSize()
    {
      LONG height = 200;
      HRESULT hr = S_OK;
      hr = g_spMIC->SetPreviewHeight(height);
    }

```

## See also

[Customizing the Math Input Control](https://learn.microsoft.com/windows/desktop/tablet/customizing-the-math-input-control)

[GetPreviewHeight](https://learn.microsoft.com/windows/desktop/api/micaut/nf-micaut-imathinputcontrol-getpreviewheight)

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)