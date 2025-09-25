# INFCONTEXT structure

## Description

The
**INFCONTEXT** structure stores context information that functions such as
[SetupGetLineText](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetlinetexta) use to navigate INF files.

## Members

### `Inf`

Handle to the INF file returned by
[SetupOpenInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopeninffilea).

### `CurrentInf`

Pointer to the current INF file. The **Inf** member may point to multiple files if they were appended to the open INF file using
[SetupOpenAppendInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenappendinffilea).

### `Section`

Section in the current INF file.

### `Line`

Line of the current section in the INF file.

**Note** The setup functions use this structure internally and it must not be accessed or modified by applications. It is included here for informational purposes only.

## See also

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupFindFirstLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindfirstlinea)

[SetupFindNextLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextline)

[SetupFindNextMatchLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextmatchlinea)

[Structures](https://learn.microsoft.com/windows/desktop/SetupApi/structures--setup-api-)