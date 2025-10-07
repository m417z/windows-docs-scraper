# PSINJECTDATA structure

## Description

The **PSINJECTDATA** structure is a header for the input buffer used with the [POSTSCRIPT_INJECTION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162830(v=vs.85)) printer escape function.

## Members

### `DataBytes`

The number of bytes of raw data to be injected. The raw data begins immediately following this structure. This size does not include the size of the **PSINJECTDATA** structure.

### `InjectionPoint`

Specifies where to inject the raw data in the PostScript output. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| PSINJECT_BEGINSTREAM | Before the first byte of job stream. |
| PSINJECT_PSADOBE | Before %!PS-Adobe. |
| PSINJECT_PAGESATEND | Replaces driver's %%Pages (atend). |
| PSINJECT_PAGES | Replaces driver's %%Pages nnn. |
| PSINJECT_DOCNEEDEDRES | After %%DocumentNeededResources. |
| PSINJECT_DOCSUPPLIEDRES | After %%DocumentSuppliedResources. |
| PSINJECT_PAGEORDER | Replaces driver's %%PageOrder. |
| PSINJECT_ORIENTATION | Replaces driver's %%Orientation. |
| PSINJECT_BOUNDINGBOX | Replaces driver's %%BoundingBox. |
| PSINJECT_DOCUMENTPROCESSCOLORS | Replaces driver's %%DocumentProcessColors \<color>. |
| PSINJECT_COMMENTS | Before %%EndComments. |
| PSINJECT_BEGINDEFAULTS | After %%BeginDefaults. |
| PSINJECT_ENDDEFAULTS | Before %%EndDefaults. |
| PSINJECT_BEGINPROLOG | After %%BeginProlog. |
| PSINJECT_ENDPROLOG | Before %%EndProlog. |
| PSINJECT_BEGINSETUP | After %%BeginSetup. |
| PSINJECT_ENDSETUP | Before %%EndSetup. |
| PSINJECT_TRAILER | After %%Trailer |
| PSINJECT_EOF | After %%EOF |
| PSINJECT_ENDSTREAM | After the last byte of job stream |
| PSINJECT_DOCUMENTPROCESSCOLORSATEND | Replaces driver's %%DocumentProcessColors (atend) |
| **Page level injection points** | |
| PSINJECT_PAGENUMBER | Replaces driver's %%Page |
| PSINJECT_BEGINPAGESETUP | After %%BeginPageSetup |
| PSINJECT_ENDPAGESETUP | Before %%EndPageSetup |
| PSINJECT_PAGETRAILER | After %%PageTrailer |
| PSINJECT_PLATECOLOR | Replace driver's %%PlateColor: \<color> |
| PSINJECT_SHOWPAGE | Before showpage operator |
| PSINJECT_PAGEBBOX | Replaces driver's %%PageBoundingBox |
| PSINJECT_ENDPAGECOMMENTS | Before %%EndPageComments |
| PSINJECT_VMSAVE | Before save operator |
| PSINJECT_VMRESTORE | After restore operator |

### `PageNumber`

The page number (starting from 1) to which the injection data is applied. Specify zero to apply the injection data to all pages. This member is meaningful only for page level injection points starting from PSINJECT_PAGENUMBER. For other injection points, set **PageNumber** to zero.

## See also

[POSTSCRIPT_INJECTION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162830(v=vs.85))

[Print Spooler API Structures](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-structures)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)