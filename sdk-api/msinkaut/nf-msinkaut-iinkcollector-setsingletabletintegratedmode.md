# IInkCollector::SetSingleTabletIntegratedMode

## Description

Allows the ink collector ([InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class), [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class), or [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)) to collect ink from only one tablet. Ink from other tablets is ignored by the ink collector.

## Parameters

### `Tablet` [in]

The tablet on which ink is collected, or drawn.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_COLLECTOR_ENABLED** | The tablet cannot change modes while the collector is enabled. |
| **E_INK_EXCEPTION** | An exception occurred while processing. |
| **E_INK_INCOMPATIBLE_OBJECT** | The tablet does not point to a compatible Ink object. |

## Remarks

To allow the ink collector to collect ink from all tablets, call the [SetAllTabletsMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setalltabletsmode) method.

**Note** The ink collector object or control that collects ink must be disabled before calling this method. To disable the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) object or the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object, set the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) property to **FALSE**. To disable the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control, set the [InkEnabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_inkenabled) property to **FALSE**. After calling the **SetSingleTabletIntegratedMode** method, re-enable the object or control by setting the **Enabled** (or **InkEnabled**) property to **TRUE**.

When this method is called, the [Cursors](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_cursors) property of the ink collector is set to the empty collection.

## See also

[Enabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled)

[IInkCollector](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkcollector)

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)

[InkTablets Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms704832(v=vs.85))

[SetAllTabletsMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setalltabletsmode)