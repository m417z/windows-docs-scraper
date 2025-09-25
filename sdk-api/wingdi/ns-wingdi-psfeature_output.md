# PSFEATURE_OUTPUT structure

## Description

The **PSFEATURE_OUTPUT** structure contains information about PostScript driver output options. This structure is used with the [GET_PS_FEATURESETTING](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd144954(v=vs.85)) printer escape function.

## Members

### `bPageIndependent`

**TRUE** if PostScript output is page-independent or **FALSE** if PostScript output is page-dependent.

### `bSetPageDevice`

**TRUE** if printer feature code (setpagedevice's) is included or **FALSE** if all printer feature code is suppressed.

## See also

[GET_PS_FEATURESETTING](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd144954(v=vs.85))

[Print Spooler API Structures](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-structures)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)