# JET_UNICODEINDEX Structure

_**Applies to:** Windows | Windows Server_

## JET_UNICODEINDEX Structure

The **JET_UNICODEINDEX** structure customizes how Unicode data gets normalized when an index is created over a Unicode column.

```cpp
typedef struct tagJET_UNICODEINDEX {
  unsigned long lcid;
  unsigned long dwMapFlags;
} JET_UNICODEINDEX;
```

### Members

**lcid**

The Locale ID to use when normalizing the data. Any locale may be used as long as the appropriate language pack has been installed on the machine. The one exception is that the Language Neutral locale (LCID of zero) is illegal.

**dwMapFlags**

These flags get passed to [LCMapString](https://learn.microsoft.com/windows/win32/api/winnls/nf-winnls-lcmapstringa) when Unicode data gets normalized to a key, which enables user-defined flags to override the default.

**Windows 2000**: The only two legal values for **dwFlags** are:

  - ( LCMAP_SORTKEY | NORM_IGNORECASE | NORM_IGNOREKANATYPE | NORM_IGNOREWIDTH | NORM_IGNORENONSPACE )

<!-- end list -->

  - ( LCMAP_SORTKEY | NORM_IGNORECASE | NORM_IGNOREKANATYPE | NORM_IGNOREWIDTH )

**dwMapFlags** has the following restrictions.

|

Value

|

Meaning

|
|--------------|----------------|
|

LCMAP_SORTKEY

|

Mandatory.

|
|

LCMAP_BYTEREV

|

Optional.

|
|

NORM_IGNORECASE

|

Optional.

|
|

NORM_IGNORENONSPACE

|

Optional.

|
|

NORM_IGNORESYMBOLS

|

Optional.

|
|

NORM_IGNOREKANATYPE

|

Optional.

|
|

NORM_IGNOREWIDTH

|

Optional.

|
|

SORT_STRINGSORT

|

Optional.

|

### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista, Windows XP, or Windows 2000 Professional.

|
|

**Server**

|

Requires Windows Server 2008, Windows Server 2003, or Windows 2000 Server.

|
|

**Header**

|

Declared in Esent.h.

|

### See Also

[JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp)
[JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure)
[JetOpenTempTable3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentemptable3-function)