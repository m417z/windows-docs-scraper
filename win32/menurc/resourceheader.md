# RESOURCEHEADER structure

Contains information about the resource header itself and the data specific to this resource. This structure is not a true C-language structure, because it contains variable-length members. The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**DataSize**

Type: **DWORD**

The size, in bytes, of the data that follows the resource header for this particular resource. It does not include any file padding between this resource and any resource that follows it in the resource file.

**HeaderSize**

Type: **DWORD**

The size, in bytes, of the resource header data that follows.

**TYPE**

Type: **DWORD**

The resource type. The **TYPE** member can either be a numeric value or a null-terminated Unicode string that specifies the name of the type. See the following Remarks section for a description of **Name** or **Ordinal** type members.

If the **TYPE** member is a numeric value, it can specify either a standard or a user-defined resource type. If the member is a string, then it is a user-defined resource type. For a list of the predefined resource types, see [Resource Types](https://learn.microsoft.com/windows/desktop/menurc/resource-types).

Values less than 256 are reserved for system use.

**NAME**

Type: **DWORD**

A name that identifies the particular resource. The **NAME** member, like the **TYPE** member, can either be a numeric value or a null-terminated Unicode string. See the following Remarks section for a description of **Name** or **Ordinal** type members.

You do not need to add padding for **DWORD** alignment between the **TYPE** and **NAME** members because they contain **WORD** data. However, you may need to add a **WORD** of padding after the **NAME** member to align the rest of the header on **DWORD** boundaries.

**DataVersion**

Type: **DWORD**

A predefined resource data version. This will determine which version of the resource data the application should use.

**MemoryFlags**

Type: **WORD**

A set of attribute flags that can describe the state of the resource. Modifiers in the .RC script file assign these attributes to the resource. The script identifiers can assign the following flag values.

Applications do not use any of these attributes. The attributes are permitted in the script for backward compatibility with existing scripts, but they are ignored. Resources are loaded when the corresponding module is loaded, and are freed when the module is unloaded.

**MOVEABLE** (0x0010)

**FIXED** (~MOVEABLE)

**PURE** (0x0020)

**IMPURE** (~PURE)

**PRELOAD** (0x0040)

**LOADONCALL** (~PRELOAD)

**DISCARDABLE** (0x1000)

**LanguageId**

Type: **WORD**

The language for the resource or set of resources. Set the value for this member with the optional [LANGUAGE](https://learn.microsoft.com/windows/win32/menurc/language-statement) resource definition statement. The parameters are constants from the Winnt.h file.

Each resource includes a language identifier so the system or application can select a language appropriate for the current locale of the system. If there are multiple resources of the same type and name that differ only in the language of the strings within the resources, you will need to specify a **LanguageId** for each one.

**Version**

Type: **DWORD**

A user-defined version number for the resource data that tools can use to read and write resource files. Set this value with the optional [VERSION](https://learn.microsoft.com/windows/win32/menurc/version-statement) resource definition statement.

**Characteristics**

Type: **DWORD**

Specifies user-defined information about the resource that tools can use to read and write resource files. Set this value with the optional [CHARACTERISTICS](https://learn.microsoft.com/windows/win32/menurc/characteristics-statement) resource definition statement.

## Remarks

A variable type member is called a **Name** or **Ordinal** member, and it is used in most places in the resource file where an identifier appears. The first **WORD** of a **Name** or **Ordinal** type member indicates whether the member is a numeric value or a string. If the first **WORD** in the member is equal to the value 0xffff, which is an invalid Unicode character, then the following **WORD** is a type number. Otherwise, the member contains a Unicode string and the first **WORD** in the member is the first character in the name string. For additional information about resource definition statements, see [Resource-Definition Statements](https://learn.microsoft.com/windows/win32/menurc/resource-definition-statements).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)

**Other Resources**

[CHARACTERISTICS Statement](https://learn.microsoft.com/windows/win32/menurc/characteristics-statement)

[LANGUAGE Statement](https://learn.microsoft.com/windows/win32/menurc/language-statement)

[VERSION Statement](https://learn.microsoft.com/windows/win32/menurc/version-statement)

