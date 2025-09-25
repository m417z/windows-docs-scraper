# IRealTimeStylus::ClearStylusQueues

## Description

Clears the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) input and output queues of data.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

The **ClearStylusQueues** method can be used to quickly clear the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) queues. This method clears the queues of all data.

#### Examples

The following C++ example code snippet shows a button click event handler that calls **IRealTimeStylus::ClearStylusQueues Method**. It also redraws the window where a [DynamicRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)) object has been drawing ink.

```cpp
void CCOMRTSDlg::OnBnClickedButtonClearTestArea()
{
	// Clear the stylus queues
	if (!SUCCEEDED(g_pRealTimeStylus->ClearStylusQueues()))
	{
		TRACE("Error clearing stylus queues.");
	}

	// Clear the status text
	m_staticGestureStatus.SetWindowTextW(L"");

	// Redraw the window to clear the ink
	this->RedrawWindow();
}

```

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[InkPicture Control Reference](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)