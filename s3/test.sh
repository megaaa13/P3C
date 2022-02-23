printf "Test -ne 2 2 : "
./test 2 -ne 2
if [ $? == 0 ]
then printf "\033[0;31m%s\n\e[0m" true 
else printf "\033[0;32m%s\n\e[0m" false
fi

printf "Test -ne 2 3 : "
./test 2 -ne 3
if [ $? == 0 ]
then printf "\033[0;32m%s\n\e[0m" true
else printf "\033[0;31m%s\n" false
fi

printf "Test -eq 2 2 : "
./test +2 -eq 2
if [ $? == 0 ]
then printf "\033[0;32m%s\n\e[0m" true 
else printf "\033[0;31m%s\n\e[0m" false
fi

printf "Test -eq 2 3 : "
./test 2 -eq 3
if [ $? == 0 ]
then printf "\033[0;31m%s\n\e[0m" true 
else printf "\033[0;32m%s\n\e[0m" false
fi

printf "Test -ge 2 3 : "
./test 2 -ge 3
if [ $? == 0 ]
then printf "\033[0;31m%s\n\e[0m" true 
else printf "\033[0;32m%s\n\e[0m" false
fi

printf "Test -ge 3 2 : "
./test 3 -ge 2
if [ $? == 0 ]
then printf "\033[0;32m%s\n\e[0m" true 
else printf "\033[0;31m%s\n\e[0m" false
fi

printf "Test -ge 2 2 : "
./test 2 -ge 2
if [ $? == 0 ]
then printf "\033[0;32m%s\n\e[0m" true 
else printf "\033[0;31m%s\n\e[0m" false
fi

printf "Test -le 2 3 : "
./test 2 -le 3
if [ $? == 0 ]
then printf "\033[0;32m%s\n\e[0m" true 
else printf "\033[0;31m%s\n\e[0m" false
fi

printf "Test -le 2 2 : "
./test 2 -le 2
if [ $? == 0 ]
then printf "\033[0;32m%s\n\e[0m" true 
else printf "\033[0;31m%s\n\e[0m" false
fi

printf "Test -le 3 2 : "
./test 3 -le 2
if [ $? == 0 ]
then printf "\033[0;31m%s\n\e[0m" true 
else printf "\033[0;32m%s\n\e[0m" false
fi

printf "Test -lt 2 3 : "
./test 2 -lt 3
if [ $? == 0 ]
then printf "\033[0;32m%s\n\e[0m" true 
else printf "\033[0;31m%s\n\e[0m" false
fi

printf "Test -lt 3 2 : "
./test 3 -lt 2
if [ $? == 0 ]
then printf "\033[0;31m%s\n\e[0m" true 
else printf "\033[0;32m%s\n\e[0m" false
fi

printf "Test -lt 3 3 : "
./test 3 -lt 3
if [ $? == 0 ]
then printf "\033[0;31m%s\n\e[0m" true 
else printf "\033[0;32m%s\n\e[0m" false
fi

printf "Test -gt 2 3 : "
./test 2 -gt 3
if [ $? == 0 ]
then printf "\033[0;31m%s\n\e[0m" true 
else printf "\033[0;32m%s\n\e[0m" false
fi

printf "Test -gt 3 2 : "
./test 3 -gt 2
if [ $? == 0 ]
then printf "\033[0;32m%s\n\e[0m" true 
else printf "\033[0;31m%s\n\e[0m" false
fi

printf "Test -gt 3 3 : "
./test 3 -gt 3
if [ $? == 0 ]
then printf "\033[0;31m%s\n\e[0m" true 
else printf "\033[0;32m%s\n\e[0m" false
fi