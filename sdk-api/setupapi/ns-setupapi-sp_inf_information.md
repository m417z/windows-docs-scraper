# SP_INF_INFORMATION structure

## Description

The
**SP_INF_INFORMATION** structure stores information about an INF file, including the style, number of constituent INF files, and version data.

## Members

### `InfStyle`

Style of the INF file. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INF_STYLE_NONE** | Specifies that the style of the INF file is unrecognized or nonexistent. |
| **INF_STYLE_OLDNT** | A legacy INF file format. |
| **INF_STYLE_WIN4** | A Windows INF file format. |

### `InfCount`

Number of constituent INF files.

### `VersionData`

Stores information from the **Version** section of an INF file in an array of **ANYSIZE_ARRAY** bytes.

## See also

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetInfInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfinformationa)

[SetupQueryInfFileInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueryinffileinformationa)

[SetupQueryInfVersionInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueryinfversioninformationa)

[Structures](https://learn.microsoft.com/windows/desktop/SetupApi/structures--setup-api-)