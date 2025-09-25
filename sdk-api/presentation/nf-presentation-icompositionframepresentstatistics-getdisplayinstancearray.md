## Description

Gets the array of display instances and its count.

## Parameters

### `displayInstanceArrayCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The count of the _`displayInstanceArray`_.

### `displayInstanceArray`

Type: **[CompositionFrameDisplayInstance](https://learn.microsoft.com/windows/win32/api/presentation/ns-presentation-compositionframedisplayinstance) \*\***

The array of display instances.

## Remarks

This data is valid for the lifetime of the `ICompositionFramePresentStatistics`, and should not be read after the `ICompositionFramePresentStatistics` is released.

## See also