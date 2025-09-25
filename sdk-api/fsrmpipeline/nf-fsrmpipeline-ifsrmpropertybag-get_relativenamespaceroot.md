# IFsrmPropertyBag::get_RelativeNamespaceRoot

## Description

The relative path of the namespace root under which the file is being evaluated.

This property is read-only.

## Parameters

## Remarks

This property is only valid under an evaluation context. Classifier modules that retrieve this property will get the namespace root of the rule under which the file is being evaluated. Because storage modules do not have evaluation contexts, they must not retrieve this property.

The relative namespace root is the path of the namespace root relative to the volume root. For example, if the path to the file is "P:\folder1\subfolderA\test.txt", and the file is being evaluated by a rule with a namespace root of "P:\folder1", then the relative namespace root would be "\folder1\". Note that the rule's namespace root determines the relative namespace root.

The caller should not expect that the relative namespace root returned will consistently have leading or trailing backslashes.

## See also

[IFsrmPropertyBag](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertybag)