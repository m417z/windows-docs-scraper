# ACTCTX_SECTION_KEYED_DATA structure

## Description

The
**ACTCTX_SECTION_KEYED_DATA** structure is used by the
[FindActCtxSectionString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findactctxsectionstringa) and
[FindActCtxSectionGuid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findactctxsectionguid) functions to return the activation context information along with either the GUID or 32-bit integer-tagged activation context section.

## Members

### `cbSize`

The size, in bytes, of the activation context keyed data structure.

### `ulDataFormatVersion`

Number that indicates the format of the data in the section where the key was found. Clients should verify that the data format version is as expected rather than trying to interpret the values of unfamiliar data formats. This number is only changed when major non-backward-compatible changes to the section data formats need to be made. The current format version is 1.

### `lpData`

Pointer to the redirection data found associated with the section identifier and key.

### `ulLength`

Number of bytes in the structure referred to by **lpData**. Note that the data structures grow over time; do not access members in the instance data that extend beyond **ulLength**.

### `lpSectionGlobalData`

Returned pointer to a section-specific data structure which is global to the activation context section where the key was found. Its interpretation depends on the section identifier requested.

### `ulSectionGlobalDataLength`

Number of bytes in the section global data block referred to by **lpSectionGlobalData**.

Note that the data structures grow over time and you may receive an old format activation context data block; do not access members in the section global data that extend beyond **ulSectionGlobalDataLength**.

### `lpSectionBase`

Pointer to the base of the section where the key was found. Some instance data contains offsets relative to the section base address, in which case this pointer value is used.

### `ulSectionTotalLength`

Number of bytes for the entire section starting at **lpSectionBase**. May be used to verify that offset/length pairs, which are specified as relative to the section base are wholly contained in the section.

### `hActCtx`

Handle to the activation context where the key was found. First, the active activation context for the thread is searched, followed by the process-default activation context and then the system-compatible-default-activation context. This member indicates which activation context contained the section and key requested. This is only returned if the FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX flag is passed.

Note that when this is returned, the caller must call
[ReleaseActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-releaseactctx)() on the activation context handle returned to release system resources when all other references to the activation context have been released.

### `ulAssemblyRosterIndex`

Cardinal number of the assembly in the activation context that provided the redirection information found. This value can be presented to [QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) for more information about the contributing assembly.

### `ulFlags`

### `AssemblyMetadata`

## Remarks

Callers should initialize the
**ACTCTX_SECTION_KEYED_DATA** structure as such:

"ACTCTX_SECTION_KEYED_DATA askd = { sizeof(askd) };"

which initializes all members to zero/null except the size field which is set correctly.

## See also

[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa)

[FindActCtxSectionGuid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findactctxsectionguid)

[FindActCtxSectionString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findactctxsectionstringa)