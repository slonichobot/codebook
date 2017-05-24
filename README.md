
## Use if you are lazy
function lazycommit
    git add -A
    git -c color.status=false status \
    | gsed -n -r -e '1,/Changes to be committed:/ d' \
            -e '1,1 d' \
            -e '/^Untracked files:/,$ d' \
            -e 's/^\s*//' \
            -e '/./p' \
    | git commit -F -
end
