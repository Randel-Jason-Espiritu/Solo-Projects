<html>
    <head>
        <title> FILIPINO DISHES WEBISTE </title>
        <body>
             <!-- REFERENCE FOR THE RECIPE'S -->
             <!-- Adobo: https://www.knorr.com/ph/recipe-ideas/chicken-adobo.html -->
             <!-- Sinigang: https://panlasangpinoy.com/sinigang-na-baboy-with-gabi/ -->
             <!-- Sisig: https://www.kawalingpinoy.com/sisig/ -->
            <?php
                // THESE ARE THE AVAILABLE DISHES
                echo "<pre>";
                echo "<h1>"."<b>FILIPINO DISHES RECIPE</b>"."</h1>"."</br>";
                echo "<b>AVAILABLE FOR SEARCH:</b>"."</br>";
                echo "1. Adobo"."</br>";
                echo "2. Sinigang"."</br>";
                echo "3. Sisig"."</br>";
                echo "</pre>";
            ?>
            <br>
            <!-- Will take user input for searching -->
            <form aciton="Test.php" method="get">
                Search Filipino Dish <input type="text" name="dish">
                <button type="submit">Search</button>
            </form>
            <!-- If the the the value is set. "if statment == TRUE" and run the php program -->
            <?php
                //ckecks if the value isset
                if (isset($_GET['dish'])){
                    //program will check if the search item is "==" to the listed available dish recipe
                    //if "if statement" == TRUE the recipe will be outputed
                    //if "if statement" == FALSE the ff output will be displayed:  Searched item Unavailable || Update Coming Soon!!!
                    if(strtolower($_GET['dish']) == "adobo")
                    {
                        //RECIPE OUTPUT
                        
                        echo "<h1>"."<b>Chicken Adobo Recipe</b>"."</h1>";
                        
                        //template: echo "\t   *<b></b> "."</br>";
                        //Igredients list
                        echo "<pre>";
                        echo "\t<b>Ingredients:</b>"."</br>";
                        echo "\t   *<b>2</b> tbsp of Preferred oil"."</br>";
                        echo "\t   *<b>6</b> cloves garlic"."</br>";
                        echo "\t   *<b>1</b> pc onion,sliced "."</br>";
                        echo "\t   *<b>1-2</b> kg chicken parts "."</br>";
                        echo "\t   *<b>2</b> tbsp of vinegar "."</br>";
                        echo "\t   *<b>1/2</b> cup soy sauce  "."</br>";
                        echo "\t   *<b>1</b> liter of water (put the necessary amount) "."</br>";
                        echo "\t   *<b>2-4</b> pcs bay leaves "."</br>";
                        echo "\t   *<b>1</b> tsp of black pepper "."</br>";
                        echo "\t   *<b>2</b> pc Knorr chicken cubes (optional) "."</br>";
                        echo "\t   *<b>1</b> tsp salt "."</br>";
                        echo "\t   *<b>1-2</b> tsp sugar "."</br>";
                        echo "</pre>";
                        echo "<br>";

                        //STEPS
                        //guide: echo "\t<b></b>"."</br>";
                        echo "<pre>";
                        echo "\t<b>STEP 1:</b>"."</br>";
                        echo "\t   Heat oil in pan and sauté garlic and onions.
        Then add chicken to the pan and sear on all sides,
        until you have a little browning in the chicken skin."."</br>"."</br>";
                        echo "\t<b>STEP 2:</b>"."</br>";
                        echo "\t   Pour in vinegar, soy sauce and water. Add bay leaves, pepper, salt, sugar and Knorr Chicken Cubes. 
        Bring to a boil over high heat then reduce heat to simmer, but do not cover the pan."."</br>"."</br>";
                        echo "\t<b>STEP 3:</b>"."</br>";
                        echo "\t   let simmer again for another 10 minutes or until sauce has thickened.
        After, serve it with a warm cup of rice and enjoy eating it with your family."."</br>"."</br>";
                        echo "</pre>";

                    }
                    else if(strtolower($_GET['dish']) == "sinigang")
                    {
                        //Recipe output
                        echo "<h1>"."<b>Sinigang na Baboy Recipe</b>"."</h1>";

                        //template: echo "\t   *<b></b> "."</br>";
                        //Ingredients list
                        echo "<pre>";
                        echo "\t<b>Ingredients:</b>"."</br>";
                        echo "\t   *<b>2</b> lbs. pork Belly sliced into cubes "."</br>";
                        echo "\t   *<b>2-3</b> cups of kangkong leaves "."</br>";
                        echo "\t   *<b>3</b> pcs green chilli pepper "."</br>";
                        echo "\t   *<b>2</b> pcs tomatoes quartered "."</br>";
                        echo "\t   *<b>1</b> cup sliced radish (labanos) "."</br>";
                        echo "\t   *<b>10-12</b> pcs of string beans cutted to bite size "."</br>";
                        echo "\t   *<b>1</b> onion quartered "."</br>";
                        echo "\t   *<b>15</b> pcs okra "."</br>";
                        echo "\t   *<b>2</b> pcs taro (gabi) "."</br>";
                        echo "\t   *<b>1-2</b> liters of water (put the necessary amount)  "."</br>";
                        echo "\t   *<b>2</b> packs of sinigang sampaloc mix (optional) "."</br>";
                        echo "\t   *<b>any</b> amount of sampaloc (optional) "."</br>";
                        echo "\t   *<b>3</b> tbsp fish sauce (patis) "."</br>";
                        echo "\t   *<b>1/4</b> tsp black pepper "."</br>";
                        echo "</pre>";
                        echo "<br>";

                        //STEPS
                        //guide: echo "\t<b>STEP :</b>"."</br>"; || echo "\t   "."</br>"."</br>";
                        echo "<pre>";
                        echo "\t<b>STEP 1:</b>"."</br>";
                        echo "\t   Pour water into a cooking pot. Let boil"."</br>"."</br>";
                        echo "\t<b>STEP 2:</b>"."</br>";
                        echo "\t   Add onion and tomato. Boil for 5 to 8 minutes."."</br>"."</br>";
                        echo "\t<b>STEP 3:</b>"."</br>";
                        echo "\t   Put the pork in the cooking pot. Boil for 25 minutes."."</br>"."</br>";
                        echo "\t<b>STEP 4:</b>"."</br>";
                        echo "\t   Add the taro. Cover and continue to boil for 30 minutes."."</br>"."</br>";
                        echo "\t<b>STEP 5:</b>"."</br>";
                        echo "\t   Add Knorr Sinigang sa Sampaloc mix, fish sauce, and ground black pepper; stir."."</br>"."</br>";
                        echo "\t<b>STEP 6:</b>"."</br>";
                        echo "\t   Put the daikon radish in. Cook for 3 to 5 minutes."."</br>"."</br>";
                        echo "\t<b>STEP 7:</b>"."</br>";
                        echo "\t   Add the chili peppers, okra, and snake beans. Cook for 7 minutes."."</br>"."</br>";
                        echo "\t<b>STEP 8:</b>"."</br>";
                        echo "\t   Add the kangkong. Cover the cooking pot and turn off the heat. Let it stay covered for 5 minutes."."</br>"."</br>";
                        echo "\t<b>STEP 9:</b>"."</br>";
                        echo "\t   Transfer to as serving bowl. Serve with a small bowl with patis and spicy chili."."</br>"."</br>";
                        echo "\t<b>STEP 10:</b>"."</br>";
                        echo "\t   Share and enjoy!"."</br>"."</br>";
                        echo "</pre>";
                    }
                    else if(strtolower($_GET['dish']) == "sisig")
                    {
                        //Recipe output
                        echo "<h1>"."<b>Sizzling Sisig Recipe</b>"."</h1>";

                        //Ingredients list
                        //template: echo "\t   *<b></b> "."</br>";
                        echo "<pre>";
                        echo "\t<b>Ingredients:</b>"."</br>";
                        echo "\t   *<b>2</b> pounds pig face (Snout, Ears, and Jowls"."</br>";
                        echo "\t   *<b>1</b> cup vinegar "."</br>";
                        echo "\t   *<b>1/4</b> cup soy sauce "."</br>";
                        echo "\t   *<b>1</b> head garlic,peeled and crushed "."</br>";
                        echo "\t   *<b>1</b> tsp pepper "."</br>";
                        echo "\t   *<b>2</b> bay leaves "."</br>";
                        echo "\t   *<b>1</b> tbsp salt "."</br>";
                        echo "\t   *<b></b>water "."</br>";
                        echo "\t   *<b>1</b> head onion, peeled and diced"."</br>";
                        echo "\t   *<b>6</b> Thai chill peppers, steamed and minced"."</br>";
                        echo "\t   *<b>1/2</b> cup of calamansi juice "."</br>";
                        echo "\t   *<b>1</b> pack maggi sarap "."</br>";
                        echo "\t   *<b>1/2</b> cup liver spread "."</br>";
                        echo "\t   *<b></b>pepper "."</br>";
                        echo "</pre>";
                        echo "<br>";
                        
                       //STEPS
                       //guide: echo "\t<b>STEP :</b>"."</br>"; || echo "\t   "."</br>"."</br>";
                       echo "<pre>";
                       echo "\t<b>STEP 1:</b>"."</br>";
                       echo "\t   In a large pot, combine pig face, vinegar, soy sauce, garlic, peppercorns, bay 
        leaves, about 1 tablespoon salt,  and enough water to completely cover pork. "."</br>"."</br>";
                       echo "\t<b>STEP 2:</b>"."</br>";
                       echo "\t   Bring to a boil, skimming scum that floats on top. Lower heat, cover, and 
        simmer for about 50 minutes to 1 hour or until meat is tender. Remove from 
        heat and drain well, discarding liquid."."</br>"."</br>";
                       echo "\t<b>STEP 3:</b>"."</br>";
                       echo "\t   Over a hot grill, grill pork for about 7 to 10 minutes on each side or until crisp 
        and slightly charred. Or arrange in a single layer on a baking sheet and broil in 
        a 450 F oven for about 4 to 5 minutes or until nicely charred. "."</br>"."</br>";
                       echo "\t<b>STEP 4:</b>"."</br>";
                       echo "\t   Remove from heat, allow to cool to touch, and chop meat."."</br>"."</br>";
                       echo "\t<b>STEP 5:</b>"."</br>";
                       echo "\t   In a large bowl, combine chopped meat, onions, chili peppers, calamansi juice., and liquid seasoning."."</br>"."</br>";
                       echo "\t<b>STEP 6:</b>"."</br>";
                       echo "\t   And liver spread and gently stir to combine. Season with salt and pepper to taste."."</br>"."</br>";
                       echo "\t<b>STEP 7:</b>"."</br>";
                       echo "\t   To serve, transfer to sizzling hot plates. (optional)"."</br>"."</br>";
                       echo"</pre>";

                    }
                    else
                    {
                        echo "<p> Searched item Unavailable</p>"."</br>";
                        echo "<b>Update Coming Soon!!!</b>";
                    }   
                }
            ?>
        </body>
    </head>
</html>