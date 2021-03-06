#include <DataStreams/NullBlockOutputStream.h>
#include <Formats/FormatFactory.h>


namespace DB
{

void registerOutputFormatNull(FormatFactory & factory)
{
    factory.registerOutputFormat("Null", [](
        WriteBuffer &,
        const Block & sample,
        const Context &,
        FormatFactory::WriteCallback,
        const FormatSettings &)
    {
        return std::make_shared<NullBlockOutputStream>(sample);
    });
}

}
