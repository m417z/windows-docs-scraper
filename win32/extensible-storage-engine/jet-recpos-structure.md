# JET_RECPOS Structure

_**Applies to:** Windows | Windows Server_

## JET_RECPOS Structure

The **JET_RECPOS** structure contains a collection of integers that represent a fractional position within an index. **centriesLT** is the number of index entries less than the current index key. **centriesInRange** is the number of index entries equal to the current key. **centriesInRange** is not supported and is always returned as 1. **centriesTotal** is the number of index entries in the index. All values are approximations with no guarantee of accuracy.

```cpp
    typedef struct {
      unsigned long cbStruct;
      unsigned long centriesLT;
      unsigned long centriesInRange;
      unsigned long centriesTotal;
    } JET_RECPOS;
```

### Members

**cbStruct**

The size of the [JET_RETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retinfo-structure) structure, in bytes. This value confirms the presence of the following fields.

**centriesLT**

The approximate number of index entries less than the current key.

**centriesInRange**

The approximate number of index entries equal to the current key. This field is always set to 1, regardless of the number of index entries that are actually equal to the current key.

**centriesTotal**

The approximate number of entries in the index.

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

[JET_RETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retinfo-structure)
[JetGetRecordPosition](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordposition-function)