npx bsb -make-world -clean-world
npx parcel build public/index.html --dist-dir build
find public ! -name index.html -type file -exec cp "{}" build \;
