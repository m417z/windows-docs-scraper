# ASM_CMP_FLAGS enumeration

## Description

The values of the **ASM_CMP_FLAGS** enumeration are used by the [IsEqual](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-iassemblyname-isequal) method to specify which portions of two assembly names to compare.

## Constants

### `ASM_CMPF_NAME:0x1`

Compare the name portion of the assembly names.

### `ASM_CMPF_MAJOR_VERSION:0x2`

Compare the major version portion of the assembly names.

### `ASM_CMPF_MINOR_VERSION:0x4`

Compare the minor version portion of the assembly names.

### `ASM_CMPF_BUILD_NUMBER:0x8`

Compare the build version portion of the assembly names.

### `ASM_CMPF_REVISION_NUMBER:0x10`

Compare the revision version portion of the assembly names.

### `ASM_CMPF_PUBLIC_KEY_TOKEN:0x20`

Compare the public key token portion of the assembly names.

### `ASM_CMPF_CULTURE:0x40`

Compare the culture portion of the assembly names.

### `ASM_CMPF_CUSTOM:0x80`

Compare the custom portion of the assembly names.

### `ASM_CMPF_ALL`

Compare all portions of the assembly names. This is equivalent to setting:

```
ASM_CMPF_NAME | ASM_CMPF_MAJOR_VERSION | ASM_CMPF_MINOR_VERSION | ASM_CMPF_REVISION_NUMBER | ASM_CMPF_BUILD_NUMBER | ASM_CMPF_PUBLIC_KEY_TOKEN | ASM_CMPF_CULTURE | ASM_CMPF_CUSTOM
```

### `ASM_CMPF_DEFAULT:0x100`

 Ignore the version number to compare assemblies with simple names.