# IViewHelper::Commit

## Description

The **Commit** method invalidates a Video Present Network (VidPN) on all graphics adapters.

## Return value

The **Commit** method returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | **Commit** successfully invalidated a VidPN. |
| **Any other error code (that is defined in *Winerror.h*) will cause TMM to not restore connections.** |  |

## Remarks

After **Commit** succeeds, the sources and targets on all of the graphics adapters are set.

TMM calls **Commit** whenever a set of operations must be applied. For example, TMM might call **Commit** after a call to the [IViewHelper::SetActiveTopology](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568174(v=vs.85)) method on a graphics adapter that requires for a source and targets to be mapped. TMM does not pass in the adapter name to **Commit** because the VidPN on all adapters should be invalidated.

A call to **Commit** will no longer replace a call to **ChangeDisplaySettingsEx**(**NULL**, **NULL**, **NULL**, 0, **NULL**). However, TMM always ends its graphics operations with a **Commit** call. For more information about **ChangeDisplaySettingsEx**, see the Microsoft Windows SDK documentation.

## See also

[IViewHelper::SetActiveTopology](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568174(v=vs.85))