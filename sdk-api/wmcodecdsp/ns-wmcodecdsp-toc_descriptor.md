# TOC_DESCRIPTOR structure

## Description

The **TOC_DESCRIPTOR** structure holds descriptive information for a table of contents.

## Members

### `guidID`

A globally unique identifier (**GUID**) that identifies an individual table of contents. This identifier has meaning only to the you, the developer. TOC Parser does not inspect or interpret this identifier.

### `wStreamNumber`

Not used.

### `guidType`

A globally unique identifier (**GUID**) that identifies a table of contents as belonging to a particular type. This identifier has meaning only to you, the developer. TOC Parser does not inspect or interpret this identifier. See Remarks.

### `wLanguageIndex`

An integer that identifies the language of a table of contents. This index has meaning only to you, the developer. TOC Parser does not inspect or interpret this index.

## Remarks

You might want to design several different type of tables of contents. In that case, you can distinguish between types by creating a **GUID** that represents each type. You can identify a table of contents as a particular type by setting the **guidType** member of a **TOC_DESCRIPTOR** structure and then passing the structure to [IToc::SetDescriptor](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itoc-setdescriptor).

## See also

[Table of Contents Parser Structures](https://learn.microsoft.com/windows/desktop/medfound/toc-parser-structures)