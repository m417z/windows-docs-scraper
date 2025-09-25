# ScriptLayout function

## Description

Converts an array of run [embedding levels](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) to a map of visual-to-logical position and/or logical-to-visual position.

## Parameters

### `cRuns` [in]

Number of runs to process.

### `pbLevel` [in]

Pointer to an array, of length indicated by *cRuns*, containing run embedding levels. Embedding levels for all runs on the line must be included, ordered logically. For more information, see the Remarks section.

### `piVisualToLogical` [out, optional]

Pointer to an array, of length indicated by *cRuns*, in which this function retrieves the run embedding levels reordered to visual order. The first array element represents the run to display at the far left, and subsequent entries should be displayed progressing from left to right. The function sets this parameter to **NULL** if there is no output.

### `piLogicalToVisual` [out, optional]

Pointer to an array, of length indicated by *cRuns*, in which this function retrieves the visual run positions. The first array element is the relative visual position where the first logical run should be displayed, the leftmost display position being 0. The function sets this parameter to **NULL** if there is no output.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

See [Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe) for a discussion of the context in which this function is normally called.

This function handles only data that pertains to a single line of text.

The run embedding levels are defined in the Unicode bidirectional algorithm. They describe the direction of a run, the direction of any runs in which it is embedded, and the direction of the paragraph. No other input is required for the call to this function. For more information, see [Unicode](https://learn.microsoft.com/windows/desktop/Intl/unicode).

The following table lists the predefined embedding levels. The application can add levels as needed.

| Level | Meaning |
| --- | --- |
| 0 | A left-to-right run in a left-to-right paragraph. |
| 1 | A right-to-left run embedded in a left-to-right run in a left-to-right paragraph. Alternatively, a right-to-left run, not embedded in another run, in a right-to-left paragraph. |
| 2 | A left-to-right run embedded in a right-to-left run of type 1. |
| 3 | A right-to-left run embedded in a left-to-right run of type 2. |

A "logical position" refers to the placement of a run relative to other runs. It is the position in a backing store, and corresponds to the order in which the user reads the text aloud. The "visual position" of a run refers to the way the run is visually displayed on the line, taking into account the possible directions that the run can have.

The application can call this function setting either *piLogicalToVisual* or *piVisualToLogical*, or both.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)