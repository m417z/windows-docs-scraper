# JET_INDEXCREATE Structure

_**Applies to:** Windows | Windows Server_

The **JET_INDEXCREATE** structure contains the information needed to create an index over data in an Extensible Storage Engine (ESE) database. The structure is used by functions such as [JetCreateIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex2-function), and in structures such as [JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate-structure) and [JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate2-structure).

``` c++
typedef struct tagJET_INDEXCREATE {
  unsigned long cbStruct;
  tchar* szIndexName;
  tchar* szKey;
  unsigned long cbKey;
  JET_GRBIT grbit;
  unsigned long ulDensity;
  union {
    unsigned long lcid;
    JET_UNICODEINDEX* pidxunicode;
  };
  union {
    unsigned long cbVarSegMac;
    JET_TUPLELIMITS* ptuplelimits;
  };
  JET_CONDITIONALCOLUMN* rgconditionalcolumn;
  unsigned long cConditionalColumn;
  JET_ERR err;
  unsigned long cbKeyMost;
} JET_INDEXCREATE;
```

### Members

**cbStruct**

The size, in bytes, of this structure. Set this member to sizeof( JET_INDEXCREATE ).

**szIndexName**

The name of the index to create.

The name of the index must meet the following conditions:

  - It must be less than JET_cbNameMost, not including the terminating null.

  - It must consist of the following characters: 0 (zero) through 9, A through Z, a through z, and all other punctuation except for "\!" (exclamation point), "," (comma), "\[" (opening bracket), and "\]" (closing bracket) — that is, ASCII characters 0x20, 0x22 through 0x2d, 0x2f through 0x5a, 0x5c, 0x5d through 0x7f.

  - It must not begin with a space.

  - It must consist of at least one nonspace character.

**szKey**

A pointer to a double-null-terminated string of null-delimited tokens.

Each token is of the form "\<direction-specifier\>\<column-name\>", where direction-specification is either "+" or "-". For example, a **szKey** of "+abc\\0-def\\0+ghi\\0" will index over the three columns "abc" (in ascending order), "def" (in descending order), and "ghi" (in ascending order). In the C language, string literals have an implied **NULL** terminator; therefore, the above string will be terminated by a double-NULL.

The number of columns specified in **szKey** may not exceed the value of **JET_ccolKeyMost** (a version-dependent constant).

At least one column must be named in **szKey**.

Obsolete behavior: After the double-NULL terminator, it is possible to specify a language ID (a WORD which gets passed into MAKELCID( langid, SORT_DEFAULT ) ) as a way to specify the LCID for the index. It is illegal to specify both a language ID in **szKey** and an LCID in [JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-unicodeindex-structure) (by setting JET_bitIndexUnicode in *grbit*).

Deprecated: After the language ID, it is possible to pass **cbVarSegMac** as a USHORT. The behavior is undefined if the USHORT is set both in **szKey** and if **cbVarSegMac** is set in the structure.

**cbKey**

The length, in bytes, of **szKey** including the two terminating nulls.

**grbit**

A group of bits that includes zero or more of the values listed in the following table.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitIndexUnique

|

Duplicate index entries (keys) are not allowed. This is enforced when [JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269288(v=exchg.10).md) is called, not when [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294137(v=exchg.10).md) is called.

|
|

JET_bitIndexPrimary

|

The index is a primary (clustered) index. Every table must have exactly one primary index. If no primary index is explicitly defined over a table, the database engine will create its own primary index.

|
|

JET_bitIndexDisallowNull

|

None of the columns over which the index is created can contain a **NULL** value.

|
|

JET_bitIndexIgnoreNull

|

Do not add an index entry for a row if all of the columns being indexed are **NULL**.

|
|

JET_bitIndexIgnoreAnyNull

|

Do not add an index entry for a row if any of the columns being indexed are **NULL**.

|
|

JET_bitIndexIgnoreFirstNull

|

Do not add an index entry for a row if the first column being indexed is **NULL**.

|
|

JET_bitIndexLazyFlush

|

Index operations will be logged lazily.

JET_bitIndexLazyFlush does not affect the laziness of data updates. If the indexing operation is interrupted by process termination, Soft Recovery will still be able to able to get the database to a consistent state, but the index might not be present.

|
|

JET_bitIndexEmpty

|

Do not attempt to build the index, because all entries would evaluate to **NULL**. **grbit** must also specify JET_bitIgnoreAnyNull when JET_bitIndexEmpty is passed. This is a performance enhancement. For example, if a new column is added to a table, an index is created over this newly added column, and all the records in the table are scanned even though they are not added to the index. Specifying JET_bitIndexEmpty skips the scanning of the table, which could potentially take a long time.

|
|

JET_bitIndexUnversioned

|

Causes index creation to be visible to other transactions. Typically a session in a transaction will not be able to see an index creation operation in another session. This flag can be useful if another transaction is likely to create the same index. The second index-create will fail instead of potentially causing many unnecessary database operations. The second transaction might not be able to use the index immediately. The index creation operation has to complete before it is usable. The session must not currently be in a transaction to create an index without version information.

|
|

JET_bitIndexSortNullsHigh

|

Specifying this flag causes **NULL** values to be sorted after data for all columns in the index.

|
|

JET_bitIndexUnicode

|

Specifying this flag affects the interpretation of the lcid/pidxunicde union field in the structure. Setting the bit means that the **pidxunicode** field actually points to a [JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294097(v=exchg.10).md) structure. JET_bitIndexUnicode is not required in order to index Unicode data. It is only used to customize the normalization of Unicode data.

|
|

JET_bitIndexTuples

|

Specifies that the index is a tuple index. See [JET_TUPLELIMITS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269207(v=exchg.10).md) for a description of a tuple index.

JET_bitIndexTuples was introduced in the Windows XP operating system.

|
|

JET_bitIndexTupleLimits

|

Specifying this flag affects the interpretation of the **cbVarSegMac/ptuplelimits** union field in the structure. Setting this bit means that the **ptuplelimits** field actually points to a [JET_TUPLELIMITS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269207(v=exchg.10).md) structure to allow custom tuple index limits (implies JET_bitIndexTuples).

JET_bitIndexTupleLimits was introduced in the Windows Server 2003 operating system.

|
|

JET_bitIndexCrossProduct 0x00004000

|

Specifying this flag for an index that has more than one key column that is a multivalued column will result in an index entry being created for each result of a cross product of all the values in those key columns. Otherwise, the index would only have one entry for each multivalue in the most significant key column that is a multivalued column and each of those index entries would use the first multivalue from any other key columns that are multivalued columns.

For example, if you specified this flag for an index over column A that has the values "red" and "blue" and over column B that has the values "1" and "2" then the following index entries would be created: "red", "1"; "red", "2"; "blue", "1"; "blue", "2". Otherwise, the following index entries would be created: "red", "1"; "blue", "1".

JET_bitIndexCrossProduct was introduced in the Windows Vista operating system.

|
|

JET_bitIndexKeyMost 0x00008000

|

Specifying this flag will cause the index to use the maximum key size specified in the **cbKeyMost** field in the structure. Otherwise, the index will use JET_cbKeyMost (255) as its maximum key size.

JET_bitIndexKeyMost was introduced in Windows Vista.

|
|

JET_bitIndexDisallowTruncation 0x00010000

|

Specifying this flag will cause any update to the index that would result in a truncated key to fail with JET_errKeyTruncated. Otherwise, keys will be silently truncated. For more information on key truncation, see the [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269329(v=exchg.10).md) function.

**Windows Vista: JET_bitIndexDisallowTruncation** is introduced in Windows Vista.

|
|

JET_bitIndexNestedTable 0x00020000

|

Specifying this flag will cause update the index over multiple multivalued columns but only with values of same **itagSequence**.

JET_bitIndexNestedTable was introduced in Windows Vista.

|

**ulDensity**

The percentage density of the initial index B+ tree. Specifying a number less than 100 uses up more space to create the index initially, but allows future growth of the index to be in place, thus avoiding internal fragmentation.

**lcid**

The locale identifier (LCID) to use when normalizing the data when the JET_bitIndexUnicode value is not specified in the *grbit* parameter. The LCID affects the normalization if the index is over Unicode columns.

**pidxunicode**

A pointer to a [JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-unicodeindex-structure) structure if the JET_bitIndexUnicode value is specified in the *grbit* parameter. This allows the user to specify custom flags that get passed to the [LCMapString](https://msdn.microsoft.com/library/dd318700/(vs.85/).aspx) function during Unicode normalization.

**cbVarSegMac**

The maximum length, in bytes, of each column to store in the index when the JET_bitIndexTupleLimits value is not specified in the *grbit* parameter.

Specifying a value of 0 (zero) for this field is equivalent to:

  - Specifying JET_cbPrimaryKeyMost for a primary index.

  - Specifying JET_cbSecondaryKeyMost for a secondary index.

**ptuplelimits**

A pointer to a [JET_TUPLELIMITS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tuplelimits-structure) structure if the JET_bitIndexTupleLimits value is specified in the *grbit* parameter.

ptuplelimits was introduced in Windows Server 2003.

**rgconditionalcolumn**

An optional parameter to an array of [JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-conditionalcolumn-structure) structures, which are used to specify the conditional columns in the index.

**cConditionalColumn**

The count of structures in the **rgconditionalcolumn** array.

**err**

Contains the return code for creating this index.

**cbKeyMost**

Specifies the maximum allowable size, in bytes, for keys in the index. This parameter is ignored if the JET_bitIndexKeyMost value is not specified in the *grbit* parameter. If this parameter is set to zero, and JET_bitIndexKeyMost is specified in the *grbit* parameter, the calling function will fail with JET_err_InvalidDef.

The minimum supported maximum key size is JET_cbKeyMostMin (255), which is the legacy maximum key size.

The maximum key size is dependent on the database page size (JET_paramDatabasePageSize), as follows:

  - If JET_paramDatabasePageSize = 2048 then JET_cbKeyMostMin (255) \<= **cbKeyMost** \<= JET_cbKeyMost2KBytePage (500)

  - If JET_paramDatabasePageSize = 4096 then JET_cbKeyMostMin (255) \<= **cbKeyMost** \<= JET_cbKeyMost4KBytePage (1000)

  - If JET_paramDatabasePageSize = 8192 then JET_cbKeyMostMin (255) \<= **cbKeyMost** \<= JET_cbKeyMost8KBytePage (2000)

The maximum supported key size for the instance can also be read from the JET_paramKeyMost system parameter.

**cbKeyMost** was introduced in Windows Vista.

### Remarks

ESE supports indexing over key columns containing multiple values. To use this feature, the column must be a tagged column type (JET_bitColumnTagged), and it must be flagged to have its multiple values indexed with JET_bitColumnMultiValued. In versions of Windows earlier than Windows Vista, only the first multivalued key column in the index will have its values expanded in the index. All other multivalued and tagged columns will only have their first values expanded in the index.

Assuming the following rows exist in a table (column Alpha is not multivalued, while columns Beta, Gamma, and Delta are multivalued), and an index is created as "+Alpha\\0+Beta\\0+Gamma\\0+Delta\\0\\0":

|

Alpha

|

Beta

|

Gamma

|

Delta

|
|--------------|-------------|--------------|--------------|
|

1

|

ABC\
GHI\
JKL

|

MNO\
PQR\
STU

|

VWX\
YZ

|
|

2

|

THE

|

RAIN\
SPAIN

|

IN\
FALLS

|

The falling index-tuples will be stored:

{1,ABC,MNO,VWX}
{1,GHI,MNO,VWX}
{1,JKL,MNO,VWX}
{2,THE,RAIN,IN}

Note that {2,THE,SPAIN,IN} is not stored, even though the Alpha column in the second row happens to have a single multivalue.

In versions of Windows starting with Windows Vista, all multivalued columns can be expanded in the index by specifying JET_bitIndexCrossProduct.

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
|

**Unicode**

|

Implemented as **JET_ INDEXCREATE_W** (Unicode) and **JET_ INDEXCREATE_A** (ANSI).

|

### See also

[JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp)
[JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-conditionalcolumn-structure)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate-structure)
[JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate2-structure)
[JET_TUPLELIMITS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tuplelimits-structure)
[JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-unicodeindex-structure)
[JetCreateIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex2-function)
[JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function)
[JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function)