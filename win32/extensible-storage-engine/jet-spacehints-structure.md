# JET_SPACEHINTS Structure

_**Applies to:** Windows | Windows Server_

## JET_SPACEHINTS Structure

The **JET_SPACEHINTS** structure contains information about space allocation patterns when a b-tree grows through append or hotpoint splits. Append splits happen when records are added to the end of a b-tree and hotpoint splits happen when multiple records are added to the same virtual insertion point (for example, adding 'Marie', 'Mark', 'Martin', 'Mary' to the middle of a b-tree that is sorted alphabetically).

**Windows 7:** The **JET_SPACEHINTS** structure is introduced in Windows 7.

```cpp
    typedef struct tagJET_SPACEHINTS {
      unsigned long cbStruct;
      unsigned long ulInitialDensity;
      unsigned long cbInitial;
      JET_GRBIT grbit;
      unsigned long ulMaintDensity;
      unsigned long ulGrowth;
      unsigned long cbMinExtent;
      unsigned long cbMaxExtent;
    } JET_SPACEHINTS;
```

### Members

**cbStruct**

The size, in bytes, of this structure. Set this member to sizeof( JET_SPACEHINTS ).

**ulInitialDensity**

The density at (append) layout.

**cbInitial**

The initial size (in bytes) of the object being created. This must be a multiple of the database page size.

**grbit**

A group of bits that contain the options to be used for this structure, which include zero or more of the following.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitSpaceHintsUtilizeParentSpace\
0x00000001

|

Changes the internal allocation policy to get space heirarchically from the immediate parent of a b-tree.

|
|

JET_bitCreateHintAppendSequential\
0x00000002

|

Enables append split behavior to grow according to the growth dynamics of the table (set by cbMinExtent, ulGrowth, cbMaxExtent).

|
|

JET_bitCreateHintHotpointSequential\
0x00000004

|

Enables hotpoint split behavior to grow according to the growth dynamics of the table (set by cbMinExtent, ulGrowth, cbMaxExtent).

|
|

JET_bitRetrieveHintTableScanForward\
0x00000010

|

If set, the client indicates that forward sequential scan is the predominant usage pattern of this table.

|
|

JET_bitRetrieveHintTableScanBackward\
0x00000020

|

If set, the client indicates that backward sequential scan is the predominant usage pattern of this table.

|
|

JET_bitDeleteHintTableSequential\
0x00000100

|

If set, the application expects this table to be cleaned up in sequential order, from lowest key to highest key.

|

**ulMaintDensity**

density to mulMaintDensity

Density to maintain at. If the space hints specify JET_bitRetrieveHintTableScanForward or JET_bitRetrieveHintTableScanBackward, table defragmentation will be triggered when the used space in the table drops below this threshold. Table defragmentation can be disabled by setting this member to zero. Setting this member to 100 will cause table defragmentation to run as soon as a page is freed.

**ulGrowth**

The percent growth from the last growth or initial size, rounded to nearest native JET allocation size.

**cbMinExtent too small**

This overrides ulGrowth if too small.

**cbMaxExtent**

The maximum value for growth in bytes. This caps ulGrowth.

### When a b-tree grows through append or hotpoint splits (as opposed to random record insertions), the amount of space the table will grow by is calculated as follows:

1. At creation, we give the b-tree cbInitial, always.

2. During the first allocation of a given area, we will allocate: cbInitial \* ulGrowth / 100 (rounded to the DB's page size), or cbMinExtent if larger.

3. During the next allocation, cbLastAlloc \* ulGrowth / 100 (rounded to the page size of the DB), or cbMinExtent if larger.

4. At some allocation (which could be the first allocation), the calculated size will exceed cbMaxExtent, and that will be the growth size thereafter.

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

[JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate2-structure)
[JET_TABLECREATE3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate3-structure)