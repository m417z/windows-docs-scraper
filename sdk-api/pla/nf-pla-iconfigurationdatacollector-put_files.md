# IConfigurationDataCollector::put_Files

## Description

Retrieves or sets the files to collect.

This property is read/write.

## Parameters

## Remarks

You can use the [IConfigurationDataCollector::FileMaxCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iconfigurationdatacollector-get_filemaxcount), [IConfigurationDataCollector::FileMaxRecursiveDepth](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iconfigurationdatacollector-get_filemaxrecursivedepth), and [IConfigurationDataCollector::FileMaxTotalSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iconfigurationdatacollector-get_filemaxtotalsize) properties to limit the number of files that PLA collects.

PLA copies the files to the location specified in the [IDataCollectorSet::LatestOutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_latestoutputlocation) property. If more than one file has the same name, PLA leaves the first file name intact and appends _n (where n is a one-based serial number) to all subsequent files with the same name. You can use the XML report to determine the origin of each file.

The property performs a depth-first search using the [FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea) and [FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea) functions. For example, assuming the following directory structure:

``` syntax
MyDir
    Subdir1
        Subdir1.1
            a.txt
            b.txt
        Subdir1.2
            c.txt
        g.txt  (folder in Subdir1)
        h.txt  (folder in Subdir1)
    Subdir 2
        subdir2.1
            y.txt
            z.txt
            subdir2.1.1
                m.txt
    q.txt  (folder in MyDir)
    s.txt  (folder in MyDir)

```

PLA would collect the files in the following order (assuming that no limits were reached):

``` syntax
q.txt
s.txt
g.txt
h.txt
a.txt
b.txt
c.txt
y.txt
z.txt
m.txt

```

## See also

[IConfigurationDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iconfigurationdatacollector)

[IConfigurationDataCollector::FileMaxCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iconfigurationdatacollector-get_filemaxcount)

[IConfigurationDataCollector::FileMaxRecursiveDepth](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iconfigurationdatacollector-get_filemaxrecursivedepth)

[IConfigurationDataCollector::FileMaxTotalSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iconfigurationdatacollector-get_filemaxtotalsize)