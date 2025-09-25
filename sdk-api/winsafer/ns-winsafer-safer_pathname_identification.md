# SAFER_PATHNAME_IDENTIFICATION structure

## Description

The **SAFER_PATHNAME_IDENTIFICATION** structure represents a path identification rule.

## Members

### `header`

A [SAFER_IDENTIFICATION_HEADER](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_identification_header) structure containing the structure header. The **dwIdentificationType** member of the header must be **SaferIdentityTypeImageName**, and the **cbStructSize** member of the header must be sizeof(SAFER_PATHNAME_IDENTIFICATION).

### `Description`

A description of the path identification rule provided by the user.

### `ImageName`

A pointer to a **null**-terminated wide character string that specifies the fully qualified path and file name to be used for path-based discrimination checks. The image name is also used to open and read the file to identify any other discrimination criteria not supplied in this structure. This member can be set to **NULL**. If the **dwCheckFlags** member of the [SAFER_IDENTIFICATION_HEADER](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_identification_header) structure specified by the **header** member includes SAFER_CRITERIA_AUTHENTICODE, either the **hImageFileHandle** member or the **ImagePath** member of the **SAFER_IDENTIFICATION_HEADER** structure must be set.

### `dwSaferFlags`

Reserved for future use.