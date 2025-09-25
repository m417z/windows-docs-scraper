# ADS_CLASS_DEF structure

## Description

The **ADS_CLASS_DEF** structure is used only as a part of **IDirectorySchemaMgmt**, which is an obsolete interface. The information that follows is provided for legacy purposes only.

The **ADS_CLASS_DEF** structure holds the definitions of an object class.

## Members

### `pszClassName`

The null-terminated Unicode string that specifies the class name.

### `dwMandatoryAttrs`

The number of mandatory class attributes.

### `ppszMandatoryAttrs`

Pointer to an array of null-terminated Unicode strings that contain the names of the mandatory attributes.

### `optionalAttrs`

Number of optional attributes of the class.

### `ppszOptionalAttrs`

Pointer to an array of null-terminated Unicode strings that contain the names of the optional attributes.

### `dwNamingAttrs`

Number of naming attributes.

### `ppszNamingAttrs`

Pointer to an array of null-terminated Unicode strings that contain the names of the naming attributes.

### `dwSuperClasses`

Number of super classes of an object of this class.

### `ppszSuperClasses`

Pointer to an array of null-terminated Unicode strings that contain the names of the super classes.

### `fIsContainer`

Flags that indicate the object of the class is a container when it is **TRUE** and not a container when **FALSE**.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)