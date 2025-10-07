# JET_SNPROG Structure

_**Applies to:** Windows | Windows Server_

## JET_SNPROG Structure

The **JET_SNPROG** structure contains information about the progress of a long-running operation. When the callback function is called to notify the status of the operation and the operation is still in progress, the last parameter of the callback function is a pointer to a **JET_SNPROG** structure.

```cpp
    typedef struct {
      unsigned long cbStruct;
      unsigned long cunitDone;
      unsigned long cunitTotal;
    } JET_SNPROG;
```

### Members

**cbStruct**

The size of the **JET_SNPROG** structure, in bytes. This value confirms the presence of the following fields.

**cunitDone**

The number of work units that are already completed during the long running function.

**cunitTotal**

The number of work units that need to be completed. This value should always be bigger than or equal to **cunitDone**.

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