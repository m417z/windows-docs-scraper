# IDataManager::get_Rules

## Description

Retrieves or sets the rules to apply to the report.

This property is read/write.

## Parameters

## Remarks

The rules modify the contents of the report after it is generated. To specify the content that TraceRpt generates, see [IDataManager::ReportSchema](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_reportschema).

The following schema defines the rules that you can specify. The **Rules** element is the root node. You can specify one or more **Group** elements, and each **Group** element can contain one or more **Rule** elements. The **Help** element is an optional user-defined element. The **Step** element defines a set of conditions and associated actions that are taken if the conditions are met.

```xml
<Rules>
    <Include name="" fatal="true|false"/>
    <Group name="" enabled="true|false">
        <Rule name="" enabled="true|false">
            <Help/>
            <Step/>
        </Rule>
    </Group>
</Rules>

```

```xml
<Step select="" fatal="true|false" sortType="first|max|min" sortValue="" sortDataType="">
    <UserInput/>
    <Exists>
        <When/>
        <Otherwise/>
    </Exists>
    <Otherwise/>
</Step>

```

```xml
<UserInput name="" expression="">
    <Description/>
</UserInput>

```

```xml
<When expression="" matchRE="">
    <Action/>
</When>
...
<Otherwise>
    <Action/>
</Otherwise>

```

```xml
<Variable name="" expression="">
</Variable>

<Warning name="">
</Warning>

<Notify type="" code="" severity="" title="">
</Notify>

<Insert select="">
    <Attribute name="" value=""/>
    <Node axis=""/>
</Insert>

```

## See also

[IDataManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatamanager)