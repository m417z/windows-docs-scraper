# IInkPicture::SetAllTabletsMode

## Description

Allows an ink collector ([InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class), [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class), or [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)) to collect ink from any tablet attached to the Tablet PC.

## Parameters

### `UseMouseForInput` [in, optional]

Optional. **VARIANT_TRUE** to use the mouse as an input device; otherwise, **VARIANT_FALSE.** The default value is **VARIANT_TRUE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_COLLECTOR_ENABLED** | Cannot change modes while the InkCollector is enabled. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INVALIDARG** | The flag is invalid. |

## Remarks

This is the default mode for an object or control that collects ink. To allow the ink collector to collect ink from only one tablet, call the [SetSingleTabletIntegratedMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setsingletabletintegratedmode) method.

**Note** The ink collector must be disabled before calling this method. To disable the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) object or the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object, set the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_enabled) property to **FALSE**. To disable the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control, set the [InkEnabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_inkenabled) property to **FALSE**. After calling the **SetAllTabletsMode** method, re-enable the object or control by setting the **Enabled** (or **InkEnabled**) property to **VARIANT_TRUE**.

When an ink collector switches from ink collection using a single tablet to ink collection using all tablets, the [Cursors](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_cursors) property is set to the empty collection.

**Note** If the **SetAllTabletsMode** method is called with the *useMouse* parameter set to **VARIANT_TRUE**, the mouse is used as an input device. If the **SetAllTabletsMode** method is then called with the *useMouse* parameter set to **VARIANT_FALSE**, the mouse is not removed from the [Cursors](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_cursors) property.

## See also

[Enabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_enabled)

[IInkCursors Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursors)

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[SetSingleTabletIntegratedMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setsingletabletintegratedmode)