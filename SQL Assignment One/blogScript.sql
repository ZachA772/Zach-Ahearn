/*
Zach Ahearn
K00282339
*/
DROP DATABASE IF EXISTS blog;
CREATE DATABASE blog;
USE blog;

/*Q14*/
CREATE TABLE BlogUser(
    user_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    /*Q11*/
    first_name VARCHAR(30) NOT NULL UNIQUE,
    sur_name VARCHAR(30) NOT NULL UNIQUE,
    user_email VARCHAR(50) NOT NULL UNIQUE,
    user_display_name VARCHAR(255) NOT NULL UNIQUE,
    /*Q15*/
    gender_male_female ENUM('M','F') NOT NULL,
    user_timestamp_created TIMESTAMP DEFAULT CURRENT_TIMESTAMP);
    
    /*Q2*/
    INSERT INTO BlogUser VALUES(NULL, 'Joey', 'Ryan', "joe@gmail.com", "Joey", 'M', NULL);
    INSERT INTO BlogUser VALUES(null, 'James', 'Sullivan', "james@gmail.com", "James", 'M', NULL);
    INSERT INTO BlogUser VALUES(null, 'Jessica', 'Kelly', "jessica@gmail.com", "Jessica", 'F', NULL);
    INSERT INTO BlogUser VALUES(null, 'John', 'Hogan', "john@gmail.com", "John", 'M', NULL);
    INSERT INTO BlogUser VALUES(null, 'Jannet', 'Carey', "jannet@gmail.com", "Jannet", 'F', NULL);
    INSERT INTO BlogUser VALUES(null, 'Jordan', 'Collins', "jordan@gmail.com", "Jordan", 'M', CURRENT_TIMESTAMP());
    /*Q9*/
    INSERT INTO BlogUser VALUES(null, 'Katie', 'Bourke', "katie@gmail.com", "Katie", 'F', NULL);
    INSERT INTO BlogUser VALUES(null, 'Zach', 'Ahearn', "zach@gmail.com", "Zach", 'M', NULL);
    /*
    select * from bloguser;
    */
    
    
    
CREATE TABLE Blog (
    blog_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    blog_url VARCHAR(255) NOT NULL UNIQUE,
    blog_title VARCHAR(255) NOT NULL,
    /*Q16*/
    blog_description TEXT(300) NOT NULL,
    blog_template_name VARCHAR(255) NOT NULL,
    user_id INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES BlogUser(user_id),
    CONSTRAINT fk_blog_user FOREIGN KEY (user_id) REFERENCES BlogUser(user_id));
    
    /*Q4*/
	INSERT INTO blog VALUES(null, "www.moneyBlog.com", "Copyright Law", 'Blog about money', 'Cool Green', 1);
	INSERT INTO blog VALUES(null, "www.how2savemoney.com", "Money Advice", 'Advice to help save money', 'Hot Pink', 1);
	INSERT INTO blog VALUES(null, "www.moneyforjoey.com", "Joey Go Fund Me", 'Joeys Go Fund Me Page', 'Sun Yellow', 1);
	INSERT INTO blog VALUES(null, "www.KeepingUpWithKatie.com", "Daily Katie Blogs", 'Blog about Katies day', 'Sea Green', 7);
	INSERT INTO blog VALUES(null, "www.BO3CustomZombies.com", "Custom Maps", 'Frequently updated list of new zombies maps', 'Blood Red', 8);
    
    /*
    select * from blog;
    */


CREATE TABLE Template (
    template_name VARCHAR(255) NOT NULL PRIMARY KEY UNIQUE,
    template_desc TEXT(255) NOT NULL,
    template_URL VARCHAR(255) NOT NULL UNIQUE);
    
/*Q3*/
INSERT INTO template VALUES('cool green', 'A warm tone of green',"http://templayes/coolgreen");
INSERT INTO template VALUES('hot pink','A strong tone of pink',"http://templayes/hotpink");
INSERT INTO template VALUES('sun yellow','A bright shade of yellow',"http://templayes/sunyellow");

/*
select * from template;
*/
CREATE TABLE Post (
    post_id INT AUTO_INCREMENT PRIMARY KEY,
    post_title VARCHAR(100) NOT NULL,
    post_content TEXT NOT NULL,
    post_comments_allowed ENUM('Y','N') NOT NULL,
    /* Question 12 - Deleting timestamp column
    post_timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    */
    blog_id INT NOT NULL,
    FOREIGN KEY (blog_id) REFERENCES BLOG(blog_id),
    CONSTRAINT fk_post_blog FOREIGN KEY (blog_id) REFERENCES BLOG(blog_id));
    
    /*Q6*/
    INSERT INTO Post VALUES(null, 'What is Copyright?',
    "Copyright is a legal concept, enacted by most governments, giving the creator of an original
	work exclusive rights to it, usually for a limited time. Generally, it is the right to copy, but also gives the copyright holder
	the right to be credited for the work, to determine who may adapt the work to other forms, who may perform the work, who
	may financially benefit from it, and other, related rights. It is an intellectual property form (like the patent, the trademark, and
	thetrade secret) applicable to any expressible form of an idea or information that is substantive and discrete.(Ref: Wikipedia)", 'Y', 1);
	/*Question 8 */
    INSERT INTO Post VALUES(null, 'How To Save Money?',
    "Money is like a universal language. It is used everywhere as a form of trade. An important tip I suggest is to put money aside into a seperate account.
    Every week or month, put a fixed amount of money into this account. This sum will build over the years, allowing you to buy
    what you like later on. (Ref: Wikipedia)", 'N', 2);
    INSERT INTO Post VALUES(null, 'Day 2',
    "Hi guys, today wasn't too eventful. I spent alot of today working away at my computer doing college work. I have a bottle
    of tequila thats staring at me right now, beckoning me. I feel like it would help me get through this work.
    Ill update you all tomrrow of what ends up happing. See you later!", 'Y', 4);
    INSERT INTO Post VALUES(null, 'Black Ops 3 Zombies Custom Maps?',
    "User: ShyGuy43 is releasing is custom remaster map Call of the Dead next Tuesday. It will come with all of the aspects of
    the original map from Black Ops 1 with a few extra features. The easter egg of the map will also be available as soon as it releases",
    'Y', 5);
    
    /*
    select * from post;
    */
    
CREATE TABLE COMMENT (
    comment_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    comment_text TEXT NOT NULL,
    comment_timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    user_id INT NOT NULL,
    post_id INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES BlogUser(user_id),
    FOREIGN KEY (post_id) REFERENCES POST(post_id),
    CONSTRAINT fk_comment_user FOREIGN KEY (user_id) REFERENCES BlogUser(user_id),
    CONSTRAINT fk_comment_post FOREIGN KEY (post_id) REFERENCES POST(post_id));
    
    
    
    /*Question 10*/
    INSERT INTO COMMENT VALUES(null, 'Thanks so much Joey, this was so helpful', NULL, 7, 1);
    INSERT INTO COMMENT VALUES(null, 'This was great, Ive really been struggling to save money recently, Thanks joe', NULL, 8, 2);
    INSERT INTO COMMENT VALUES(null, 'Good Luck on your college stuff Katie!', NULL, 4, 3);
    INSERT INTO COMMENT VALUES(null, 'Im so excited for this map to release!', NULL, 2, 4);
    INSERT INTO COMMENT VALUES(null, 'Adding this to my calendar, this blog is sooooo good', NULL, 5, 4);
    
    /*
    select * from comment;
    */
    
CREATE TABLE Blog_Keyword (
	/*Q13*/
    blg_keyword VARCHAR(100) NOT NULL,
    blog_id INT NOT NULL,
    FOREIGN KEY (blog_id) REFERENCES BLOG(blog_id),
    CONSTRAINT unique_blog_keyword UNIQUE (blg_keyword, blog_id),
    CONSTRAINT fk_blog_keyword_blog FOREIGN KEY (blog_id) REFERENCES BLOG(blog_id));
    
    /*Q5*/
    INSERT INTO Blog_Keyword VALUES('Copyright', 1);
    INSERT INTO Blog_Keyword VALUES('law', 1);
    INSERT INTO Blog_Keyword VALUES('Intellectual Property', 1);
    INSERT INTO Blog_Keyword VALUES('Katie Blog', 4);
    INSERT INTO Blog_Keyword VALUES('Katies Life', 4);
    INSERT INTO Blog_Keyword VALUES('Black Ops 3', 5);
    INSERT INTO Blog_Keyword VALUES('Custom Maps', 5);
    

CREATE TABLE Post_Keyword (
    keyword VARCHAR(255) NOT NULL,
    post_id INT NOT NULL,
    FOREIGN KEY (post_id) REFERENCES POST(post_id),
    CONSTRAINT unique_post_keyword UNIQUE (keyword, post_id),
    CONSTRAINT fk_post_keyword_post FOREIGN KEY (post_id) REFERENCES POST(post_id));
    
    /*Q7*/
    INSERT INTO Post_Keyword VALUES('Copyright', 1);
    INSERT INTO Post_Keyword VALUES('law', 1);
    INSERT INTO Post_Keyword VALUES('finance', 1);
    INSERT INTO Post_Keyword VALUES('Katie Blog', 3);
    INSERT INTO Post_Keyword VALUES('Katies Life', 3);
    INSERT INTO Post_Keyword VALUES('Black Ops 3', 4);
    INSERT INTO Post_Keyword VALUES('Custom Maps', 4);
    
    /*
    DELETE FROM blog WHERE blog_id=1;
    */
    /*Q17 - This command cannot be executed because blog_id 1 is used in other tables as a foreign key.
    This means it is a parent row and is needed in other tables and therefore cannot be deleted. */