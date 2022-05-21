#!/bin/bash
FILE="$1"
basename="$(basename "$1")"

cppheader="$(echo "${basename}" | tr '[:lower:]' '[:upper:]' | tr '-' '_')"
namespace="$(echo "${basename}" | tr '-' '_')"



echo "#ifndef ${cppheader}_H
#define ${cppheader}_H

#endif // ${cppheader}_H " > "${FILE}.h"

echo "#include \"${FILE}.h\"

namespace ${namespace} {

} // namespace ${namespace}" > "${FILE}.cc"

echo "Created ${FILE}.h ${FILE}.cc"