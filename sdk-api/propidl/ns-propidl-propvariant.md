# PROPVARIANT structure

## Description

The
**PROPVARIANT** structure is used in the
[ReadMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-readmultiple) and
[WriteMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writemultiple) methods of
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) to define the type tag and the value of a property in a property set.

The **PROPVARIANT** structure is also used by the [GetValue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb761473(v=vs.85)) and [SetValue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb761475(v=vs.85)) methods of [IPropertyStore](https://learn.microsoft.com/windows/win32/api/propsys/nn-propsys-ipropertystore), which replaces [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) as the primary way to program item properties in Windows Vista. For more information, see [Property Handlers](https://learn.microsoft.com/previous-versions//bb776861(v=vs.85)).

There are five members. The first member, the value-type tag, and the last member, the value of the property, are significant. The middle three members are reserved for future use.

**Note** The **bool** member in previous definitions of this structure has been renamed to **boolVal**, because some compilers now recognize **bool** as a keyword.

**Note** The
**PROPVARIANT** structure, defined below, includes types that can be serialized in the version 1 property set serialization format. The version 1 format supports all types allowed in the version 0 format plus some additional types. The added types include "Version 1" in the comment field below. Use these types only if a version 1 property set is intended. For more information, see
[Property Set Serialization](https://learn.microsoft.com/windows/desktop/Stg/version-0-vs--version-1-property-set-serialization).

The
**PROPVARIANT** structure is defined as follows:

## Members

### `tag_inner_PROPVARIANT`

### `tag_inner_PROPVARIANT.vt`

Value type tag.

### `tag_inner_PROPVARIANT.wReserved1`

Reserved for future use.

### `tag_inner_PROPVARIANT.wReserved2`

Reserved for future use.

### `tag_inner_PROPVARIANT.wReserved3`

Reserved for future use.

### `tag_inner_PROPVARIANT.cVal`

**VT_I1**, Version 1

### `tag_inner_PROPVARIANT.bVal`

**VT_UI1**

### `tag_inner_PROPVARIANT.iVal`

**VT_I2**

### `tag_inner_PROPVARIANT.uiVal`

**VT_UI2**

### `tag_inner_PROPVARIANT.lVal`

**VT_I4**

### `tag_inner_PROPVARIANT.ulVal`

**VT_UI4**

### `tag_inner_PROPVARIANT.intVal`

**VT_INT**, Version 1

### `tag_inner_PROPVARIANT.uintVal`

**VT_UINT**, Version 1

### `tag_inner_PROPVARIANT.hVal`

**VT_I8**

### `tag_inner_PROPVARIANT.uhVal`

**VT_UI8**

### `tag_inner_PROPVARIANT.fltVal`

**VT_R4**

### `tag_inner_PROPVARIANT.dblVal`

**VT_R8**

### `tag_inner_PROPVARIANT.boolVal`

**VT_BOOL**

### `tag_inner_PROPVARIANT.scode`

**VT_ERROR**

### `tag_inner_PROPVARIANT.cyVal`

**VT_CY**

### `tag_inner_PROPVARIANT.date`

**VT_DATE**

### `tag_inner_PROPVARIANT.filetime`

**VT_FILETIME**

### `tag_inner_PROPVARIANT.puuid`

**VT_CLSID**

### `tag_inner_PROPVARIANT.pclipdata`

**VT_CF**

### `tag_inner_PROPVARIANT.bstrVal`

**VT_BSTR**

### `tag_inner_PROPVARIANT.bstrblobVal`

**VT_BSTR_BLOB**

### `tag_inner_PROPVARIANT.blob`

**VT_BLOB**, **VT_BLOBOBJECT**

### `tag_inner_PROPVARIANT.pszVal`

**VT_LPSTR**

### `tag_inner_PROPVARIANT.pwszVal`

**VT_LPWSTR**

### `tag_inner_PROPVARIANT.punkVal`

**VT_UNKNOWN**

### `tag_inner_PROPVARIANT.pdispVal`

**VT_DISPATCH**, Version 1

### `tag_inner_PROPVARIANT.pStream`

**VT_STREAM**, **VT_STREAMED_OBJECT**

### `tag_inner_PROPVARIANT.pStorage`

**VT_STORAGE**, **VT_STORED_OBJECT**

### `tag_inner_PROPVARIANT.pVersionedStream`

**VT_VERSIONED_STREAM**

### `tag_inner_PROPVARIANT.parray`

**VT_ARRAY** | **VT_***, Version 1

### `tag_inner_PROPVARIANT.cac`

**VT_VECTOR** | **VT_I1**, Version 1

### `tag_inner_PROPVARIANT.caub`

**VT_VECTOR** | **VT_UI1**

### `tag_inner_PROPVARIANT.cai`

**VT_VECTOR** | **VT_I2**

### `tag_inner_PROPVARIANT.caui`

**VT_VECTOR** | **VT_UI2**

### `tag_inner_PROPVARIANT.cal`

**VT_VECTOR** | **VT_I4**

### `tag_inner_PROPVARIANT.caul`

**VT_VECTOR** | **VT_UI4**

### `tag_inner_PROPVARIANT.cah`

**VT_VECTOR** | **VT_I8**

### `tag_inner_PROPVARIANT.cauh`

**VT_VECTOR** | **VT_UI8**

### `tag_inner_PROPVARIANT.caflt`

**VT_VECTOR** | **VT_R4**

### `tag_inner_PROPVARIANT.cadbl`

**VT_VECTOR** | **VT_R8**

### `tag_inner_PROPVARIANT.cabool`

**VT_VECTOR** | **VT_BOOL**

### `tag_inner_PROPVARIANT.cascode`

**VT_VECTOR** | **VT_ERROR**

### `tag_inner_PROPVARIANT.cacy`

**VT_VECTOR** | **VT_CY**

### `tag_inner_PROPVARIANT.cadate`

**VT_VECTOR** | **VT_DATE**

### `tag_inner_PROPVARIANT.cafiletime`

**VT_VECTOR** | **VT_FILETIME**

### `tag_inner_PROPVARIANT.cauuid`

**VT_VECTOR** | **VT_CLSID**

### `tag_inner_PROPVARIANT.caclipdata`

**VT_VECTOR** | **VT_CF**

### `tag_inner_PROPVARIANT.cabstr`

**VT_VECTOR** | **VT_BSTR**

### `tag_inner_PROPVARIANT.cabstrblob`

**VT_VECTOR** | **VT_BSTR**

### `tag_inner_PROPVARIANT.calpstr`

**VT_VECTOR** | **VT_LPSTR**

### `tag_inner_PROPVARIANT.calpwstr`

**VT_VECTOR** | **VT_LPWSTR**

### `tag_inner_PROPVARIANT.capropvar`

**VT_VECTOR** | **VT_VARIANT**

### `tag_inner_PROPVARIANT.pcVal`

**VT_BYREF** | **VT_I1**, Version 1

### `tag_inner_PROPVARIANT.pbVal`

**VT_BYREF** | **VT_UI1**, Version 1

### `tag_inner_PROPVARIANT.piVal`

**VT_BYREF** | **VT_I2**, Version 1

### `tag_inner_PROPVARIANT.puiVal`

**VT_BYREF** | **VT_UI2**, Version 1

### `tag_inner_PROPVARIANT.plVal`

**VT_BYREF** | **VT_I4**, Version 1

### `tag_inner_PROPVARIANT.pulVal`

**VT_BYREF** | **VT_UI4**, Version 1

### `tag_inner_PROPVARIANT.pintVal`

**VT_BYREF** | **VT_INT**, Version 1

### `tag_inner_PROPVARIANT.puintVal`

**VT_BYREF** | **VT_UINT**, Version 1

### `tag_inner_PROPVARIANT.pfltVal`

**VT_BYREF** | **VT_R4**, Version 1

### `tag_inner_PROPVARIANT.pdblVal`

**VT_BYREF** | **VT_R8**, Version 1

### `tag_inner_PROPVARIANT.pboolVal`

**VT_BYREF** | **VT_R8**, Version 1

### `tag_inner_PROPVARIANT.pdecVal`

**VT_BYREF** | **VT_DECIMAL**, Version 1

### `tag_inner_PROPVARIANT.pscode`

**VT_BYREF** | **VT_ERROR**, Version 1

### `tag_inner_PROPVARIANT.pcyVal`

**VT_BYREF** | **VT_CY**, Version 1

### `tag_inner_PROPVARIANT.pdate`

**VT_BYREF** | **VT_DATE**, Version 1

### `tag_inner_PROPVARIANT.pbstrVal`

**VT_BYREF** | **VT_BSTR**, Version 1

### `tag_inner_PROPVARIANT.ppunkVal`

**VT_BYREF** | **VT_UNKNOWN**, Version 1

### `tag_inner_PROPVARIANT.ppdispVal`

**VT_BYREF** | **VT_DISPATCH**, Version 1

### `tag_inner_PROPVARIANT.pparray`

**VT_BYREF** | **VT_DISPATCH**, Version 1

### `tag_inner_PROPVARIANT.pvarVal`

**VT_BYREF** | **VT_VARIANT**, Version 1

### `decVal`

 **VT_BYREF** | **VT_DECIMAL**, Version 1

## Remarks

The
**PROPVARIANT** structure can also hold a value of **VT_DECIMAL**:

``` syntax
    DECIMAL       decVal;        //VT_DECIMAL
```

However, the value of the **DECIMAL** structure requires special handling. The **DECIMAL** structure is the same size as an entire
**PROPVARIANT** structure and does not fit into the union that holds all other types of values. Instead, the value of the **DECIMAL** structure occupies the entire
**PROPVARIANT** structure, including the reserved fields and the **vt** member. However, the first member of the **DECIMAL** structure is not used and is equal in size to the **vt** member of the
**PROPVARIANT** structure. Therefore, the
**PROPVARIANT** structure declaration in the Propidl.h header file of Win32 defines the **decVal** member in such a way that it corresponds to the beginning of the
**PROPVARIANT** structure. Therefore, to put the value of the **DECIMAL** structure into a
**PROPVARIANT** structure, the value must be loaded into the **decVal** member and the **vt** member is set to **VT_DECIMAL**, just as for any other value.

**PROPVARIANT** is the fundamental data type by which property values are read and written through the
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface.

The data type
**PROPVARIANT** is related to the data type **VARIANT**, defined as part of Automation in OLE2. Several definitions are reused from Automation, as follows:

``` syntax
typedef struct  tagCY {
    unsigned long      Lo;
    long               Hi;
    } CY;

typedef struct  tagDEC {
    USHORT             wReserved;
    BYTE               scale;
    BYTE               sign;
    ULONG              Hi32;
    ULONGLONG          Lo64;
    } DECIMAL;

typedef struct  tagSAFEARRAYBOUND {
    ULONG              cElements;
    LONG               lLbound;
    } SAFEARRAYBOUND;

typedef struct  tagSAFEARRAY {
    USHORT             cDims;
    USHORT             fFeatures;
    ULONG              cbElements;
    ULONG              cLocks;
    PVOID              pvData;
    SAFEARRAYBOUND     rgsabound [ * ];
    } SAFEARRAY;

typedef CY             CURRENCY;
typedef short          VARIANT_BOOL;
typedef unsigned short VARTYPE;
typedef double         DATE;
typedef OLECHAR*       BSTR;
```

In addition, some types are unique to the
**PROPVARIANT** structure:

``` syntax
typedef struct  tagCLIPDATA {
    // cbSize is the size of the buffer pointed to
    // by pClipData, plus sizeof(ulClipFmt)
    ULONG              cbSize;
    long               ulClipFmt;
    BYTE*              pClipData;
    } CLIPDATA;
```

Among the unique
**PROPVARIANT** types are several data types that define counted arrays of other data types. The data types of all counted arrays begin with the letters **CA**, for example **CAUB**, and have an **OR** operator **vt** value (the VarType of the element and an **OR** operator with **VT_VECTOR**). The counted array structure has the following form (where *name* is the specific name of the counted array).

``` syntax
#define TYPEDEF_CA(type, name)

    typedef struct tag ## name {\
        ULONG cElems;\
        type *pElems;\
        } name
```

| Propvariant type | Code | Propvariant member | Value representation |
| --- | --- | --- | --- |
| **VT_EMPTY** | 0 | None | A property with a type indicator of **VT_EMPTY** has no data associated with it; that is, the size of the value is zero. |
| **VT_NULL** | 1 | None | This is like a pointer to **NULL**. |
| **VT_I1** | 16 | **cVal** | 1-byte signed integer. |
| **VT_UI1** | 17 | **bVal** | 1-byte unsigned integer. |
| **VT_I2** | 2 | **iVal** | Two bytes representing a 2-byte signed integer value. |
| **VT_UI2** | 18 | **uiVal** | 2-byte unsigned integer. |
| **VT_I4** | 3 | **lVal** | 4-byte signed integer value. |
| **VT_UI4** | 19 | **ulVal** | 4-byte unsigned integer. |
| **VT_INT** | 22 | **intVal** | 4-byte signed integer value (equivalent to **VT_I4**). |
| **VT_UINT** | 23 | **uintVal** | 4-byte unsigned integer (equivalent to **VT_UI4**). |
| **VT_I8** | 20 | **hVal** | 8-byte signed integer. |
| **VT_UI8** | 21 | **uhVal** | 8-byte unsigned integer. |
| **VT_R4** | 4 | **fltVal** | 32-bit IEEE floating point value. |
| **VT_R8** | 5 | **dblVal** | 64-bit IEEE floating point value. |
| **VT_BOOL** | 11 | **boolVal** (**bool** in earlier designs) | Boolean value, a **WORD** that contains 0 (**FALSE**) or -1 (**TRUE**). |
| **VT_ERROR** | 10 | **scode** | A **DWORD** that contains a status code. |
| **VT_CY** | 6 | **cyVal** | 8-byte two's complement integer (scaled by 10,000). This type is commonly used for currency amounts. |
| **VT_DATE** | 7 | **date** | A 64-bit floating point number representing the number of days (not seconds) since December 31, 1899. For example, January 1, 1900, is 2.0, January 2, 1900, is 3.0, and so on). This is stored in the same representation as **VT_R8**. |
| **VT_FILETIME** | 64 | **filetime** | 64-bit **FILETIME** structure as defined by Win32. It is recommended that all times be stored in Universal Coordinate Time (UTC). |
| **VT_CLSID** | 72 | **puuid** | Pointer to a class identifier (CLSID) (or other globally unique identifier (GUID)). |
| **VT_CF** | 71 | **pclipdata** | Pointer to a **CLIPDATA** structure, described above. |
| **VT_BSTR** | 8 | **bstrVal** | Pointer to a null-terminated Unicode string. The string is immediately preceded by a **DWORD** representing the byte count, but **bstrVal** points past this **DWORD** to the first character of the string. **BSTR**s must be allocated and freed using the Automation **SysAllocString** and **SysFreeString** calls. |
| **VT_BSTR_BLOB** | 0xfff | **bstrblobVal** | For system use only. |
| **VT_BLOB** | 65 | **blob** | **DWORD** count of bytes, followed by that many bytes of data. The byte count does not include the four bytes for the length of the count itself; an empty **blob** member would have a count of zero, followed by zero bytes. This is similar to the value **VT_BSTR**, but does not guarantee a null byte at the end of the data. |
| **VT_BLOBOBJECT** | 70 | **blob** | A **blob** member that contains a serialized object in the same representation that would appear in **VT_STREAMED_OBJECT**. That is, a **DWORD** byte count (where the byte count does not include the size of itself) which is in the format of a class identifier followed by initialization data for that class. <br><br>The only significant difference between **VT_BLOB_OBJECT** and **VT_STREAMED_OBJECT** is that the former does not have the system-level storage overhead that the latter would have, and is therefore more suitable for scenarios involving numbers of small objects. |
| **VT_LPSTR** | 30 | **pszVal** | A pointer to a null-terminated ANSI string in the system default code page. |
| **VT_LPWSTR** | 31 | **pwszVal** | A pointer to a null-terminated Unicode string in the user default locale. |
| **VT_UNKNOWN** | 13 | **punkVal** | New. |
| **VT_DISPATCH** | 9 | **pdispVal** | New. |
| **VT_STREAM** | 66 | **pStream** | A pointer to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface that represents a stream which is a sibling to the "Contents" stream. |
| **VT_STREAMED_OBJECT** | 68 | **pStream** | As in **VT_STREAM**, but indicates that the stream contains a serialized object, which is a CLSID followed by initialization data for the class. The stream is a sibling to the "Contents" stream that contains the property set. |
| **VT_STORAGE** | 67 | **pStorage** | A pointer to an [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface, representing a storage object that is a sibling to the "Contents" stream. |
| **VT_STORED_OBJECT** | 69 | **pStorage** | As in **VT_STORAGE**, but indicates that the designated [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) contains a loadable object. |
| **VT_VERSIONED_STREAM** | 73 | **pVersionedStream** | A stream with a GUID version. |
| **VT_DECIMAL** | 14 | **decVal** | A **DECIMAL** structure. |
| **VT_VECTOR** | 0x1000 | **ca*** | If the type indicator is combined with **VT_VECTOR** by using an **OR** operator, the value is one of the counted array values. This creates a **DWORD** count of elements, followed by a pointer to the specified repetitions of the value. <br><br>For example, a type indicator of **VT_LPSTR**|**VT_VECTOR** has a **DWORD** element count, followed by a pointer to an array of **LPSTR** elements.<br><br>**VT_VECTOR** can be combined by an **OR** operator with the following types: **VT_I1**, **VT_UI1**, **VT_I2**, **VT_UI2**, **VT_BOOL**, **VT_I4**, **VT_UI4**, **VT_R4**, **VT_R8**, **VT_ERROR**, **VT_I8**, **VT_UI8**, **VT_CY**, **VT_DATE**, **VT_FILETIME**, **VT_CLSID**, **VT_CF**, **VT_BSTR**, **VT_LPSTR**, **VT_LPWSTR**, and **VT_VARIANT**. **VT_VECTOR** can also be combined by an **OR** operation with **VT_BSTR_BLOB**, however it is for system use only. |
| **VT_ARRAY** | 0x2000 | **Parray** | If the type indicator is combined with **VT_ARRAY** by an **OR** operator, the value is a pointer to a SAFEARRAY. **VT_ARRAY** can use the **OR** with the following data types: **VT_I1**, **VT_UI1**, **VT_I2**, **VT_UI2**, **VT_I4**, **VT_UI4**, **VT_INT**, **VT_UINT**, **VT_R4**, **VT_R8**, **VT_BOOL**, **VT_DECIMAL**, **VT_ERROR**, **VT_CY**, **VT_DATE**, **VT_BSTR**, **VT_DISPATCH**, **VT_UNKNOWN**, and **VT_VARIANT**. **VT_ARRAY** cannot use **OR** with **VT_VECTOR**. |
| **VT_BYREF** | 0x4000 | **p*** | If the type indicator is combined with **VT_BYREF** by an **OR** operator, the value is a reference. Reference types are interpreted as a reference to data, similar to the reference type in C++ (for example, "int&"). <br><br>VT_BYREF can use **OR** with the following types: **VT_I1**, **VT_UI1**, **VT_I2**, **VT_UI2**, **VT_I4**, **VT_UI4**, **VT_INT**, **VT_UINT**, **VT_R4**, **VT_R8**, **VT_BOOL**, **VT_DECIMAL**, **VT_ERROR**, **VT_CY**, **VT_DATE**, **VT_BSTR**, **VT_UNKNOWN**, **VT_DISPATCH**, **VT_ARRAY**, and **VT_VARIANT**. |
| **VT_VARIANT** | 12 | **capropvar** | A **DWORD** type indicator followed by the corresponding value. **VT_VARIANT** can be used only with **VT_VECTOR** or **VT_BYREF**. |
| **VT_TYPEMASK** | 0xFFF |  | Used as a mask for **VT_VECTOR** and other modifiers to extract the raw VT value. |

Clipboard format identifiers, stored with the tag VT_CF, use one of five representations, identified in the **ulClipFmt** member of the **CLIPDATA** structure using the **pClipData** pointer to the particular data type.

| **ulClipFmt** value | **pClipData** value |
| --- | --- |
| -1L | A **DWORD** that contains a built-in Windows clipboard format value. |
| -2L | A **DWORD** that contains a Macintosh clipboard format value. |
| -3L | A GUID that contains a format identifier (FMTID). This is rarely used. |
| any positive value | A null-terminated string that contains a Windows clipboard format name, one suitable for passing to the **RegisterClipboardFormat** function. This function registers a new clipboard format. If a registered format with the specified name already exists, a new format is not registered and the return value identifies the existing format. This enables more than one application to copy and paste data using the same registered clipboard format. The format name comparison is case insensitive and is identified by values in the range from 0xC000 through 0xFFFF. The code page used for characters in the string is according to the code-page indicator. The "positive value" here is the string length, including the null byte at the end. When register clipboard formats are placed on or retrieved from the clipboard, they must be in the form of an **HGLOBAL** data-type value, which provides the handle to the object. |
| 0L | No data (rarely used). |

If the value of the **ulClipFmt** member is -1, the data is in the form of a built-in Windows format. In this case, the first **DWORD** of the buffer pointed to by **pClipData** is the clipboard format identifier, for example CF_METAFILEPICT. In the case of CF_METAFILEPCT, what follows is a variation on the **METAFILEPICT** structure (it uses **WORD**, rather than **DWORD** data types). That is, this data is in the following form:

``` syntax
struct PACKEDMETA
{
    WORD mm;
    WORD xExt;
    WORD yExt
    WORD reserved;
};
```

After the **METAFILEPICT** structure is the metafile data, suitable to be passed to the **SetMetaFileBitsEx** function. This function creates a memory-based, Windows-format metafile from the supplied data. This function is provided for compatibility with 16-bit versions of Windows. Win32-based applications should use the **SetEnhMetaFileBits** function. This function retrieves the contents of the specified enhanced-format metafile and copies them into a buffer. If the function succeeds and the buffer pointer is **NULL**, the return value is the size of the enhanced metafile in bytes. If the function succeeds and the buffer pointer is a valid pointer, the return value is the number of bytes copied to the buffer. If the function fails, the return value is zero.

When register clipboard formats are placed on or retrieved from the clipboard, they must be in the form of an **HGLOBAL** value.