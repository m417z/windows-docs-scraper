# IConsole2::SetStatusText

## Description

The **IConsole2::SetStatusText** method enables the snap-in to change the text in the status bar. Be aware that this is used only by instances of
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent).

## Parameters

### `pszStatusText` [in]

A pointer to a null-terminated string that contains text to be displayed in the status bar.

## Return value

This method can return one of these values.

## Remarks

The status bar has three sections, which are delineated by the pipe character (|). For example, setting the text in the status bar to "Left| Middle| Right" places "Left" in the leftmost section of the status bar, " Middle" in the middle section, and " Right" in the rightmost section.

If more than three fields are delineated (that is, there are more than two pipes), then everything that would be placed in the fourth and higher fields is omitted.

In addition, the middle section is designed to function as a progress bar. This functionality is invoked by passing the '%' character as the first character, followed by a number between 0 and 100, into the middle section. Instead of text, this section then displays a progress bar that is zero to 100 percent complete. For example, passing "Done|%75" places "Done" in the left section and a progress bar 75% complete in the middle section.

To display a string that begins with '%' in the middle section of the status bar, then begin the string with '%%'. This causes the middle section to display text and removes the first '%'. For example: "Today is|%%Wednesday%" results in the left section that contains "Today is" and the middle section that contains "%Wednesday%". If an invalid number or non-numeric text is entered in the middle section following a '%', then the middle section is empty. If a '%' is the only character in the section, then it will be shown as text.

This method should be called from an
[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2) interface pointer obtained through
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent).

Only the snap-in that owns the currently selected scope item can change the status bar text.

In MMC version 1.1 and later, each multiple-document interface (MDI) child window has a status bar.

## See also

[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2)